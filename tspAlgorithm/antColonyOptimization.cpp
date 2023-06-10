#include <bits/stdc++.h>
#include "func.hpp"
#include "antColonyOptimization.hpp"
using namespace std;


Ant::Ant(const size_t &NUM) : CITY_NUM(NUM), PATH(NUM), VISITED(NUM) {
}

void Ant::clean() {
    TOTAL_DISTANCE = 0;
    MOVE_CNT = 0;
    fill(VISITED.begin(), VISITED.end(), false);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randint(0, CITY_NUM - 1);
    CURRENT_CITY = randint(gen);
    PATH[MOVE_CNT++] = CURRENT_CITY;
    VISITED[CURRENT_CITY] = true;
}

void Ant::next(const double &ALPHA, const double &BETA,
            const vector<vector<double>> &DIST,
            const vector<vector<double>> &PHER) {
    vector<double> probabilities(CITY_NUM, 0.0);
    while (MOVE_CNT < CITY_NUM){
        for (int idx = 0; idx < CITY_NUM; idx++) {
            if (!VISITED[idx]) probabilities[idx] = pow(PHER[CURRENT_CITY][idx], ALPHA) / pow(DIST[CURRENT_CITY][idx], BETA);
            else probabilities[idx] = 0;
        }
        // Just choose the largest element as the next city.
        int idx = max_element(probabilities.begin(), probabilities.end()) - probabilities.begin();
        PATH[MOVE_CNT++] = idx;
        VISITED[idx] = true;
        TOTAL_DISTANCE += DIST[CURRENT_CITY][idx];
        CURRENT_CITY = idx;
    }
}

void Ant::search(const double &ALPHA, const double &BETA,
            const vector<vector<double>> &DIST,
            const vector<vector<double>> &PHER){
    clean();
    next(ALPHA, BETA, DIST, PHER);
    TOTAL_DISTANCE += DIST[PATH[CITY_NUM - 1]][PATH[0]];
}


void updatePheromone(vector<vector<double>> &pher,
                     const vector<Ant> &ants, const size_t &num,
                     const double &rho, const double &q){
    vector<vector<double>> temp(num, vector<double>(num, 0));
    for (const Ant &x : ants){
        for (int idx = 1; idx < num; ++idx){
            int start = x.PATH[idx - 1], end = x.PATH[idx];
            temp[start][end] += q / x.TOTAL_DISTANCE;
            temp[end][start] = temp[start][end];
        }
    }
    for (int idx = 0; idx < num; ++idx){
        for (int jdx = 0; jdx < num; ++jdx){
            pher[idx][jdx] = pher[idx][jdx] * rho + temp[idx][jdx];
        }
    }
}


void antColonyOptimizationThread(const vector<pair<double, double>>& coords, const int startAntIndex, const int endAntIndex, const double alpha, const double beta, vector<vector<double>>& pher, vector<vector<double>>& dist, vector<Ant>& ants) {
    for (int idx = startAntIndex; idx < endAntIndex; ++idx) {
        Ant& ant = ants[idx];
        ant.search(alpha, beta, dist, pher);
    }
}

tuple<vector<int>, vector<double>, double, long long> 
antColonyOptimization(const pair<string, vector<pair<double, double>>> &coords, const int &ant_num,
                        const double &alpha, const double &beta,
                        const double &tau, const double &rho,
                        const double &q, const int &iter,
                        const bool &verbose, int numThreads) {

    vector<double> distHistory;
    size_t city_num = coords.second.size();
    vector<vector<double>> pher(city_num, vector<double>(city_num, tau));
    vector<vector<double>> dist = initDist(coords.second, coords.first);
    vector<Ant> ants (ant_num, Ant(city_num));
    double bestDist = numeric_limits<double>::infinity();
    vector<int> bestPath;

    if (!numThreads) numThreads = thread::hardware_concurrency();
    vector<thread> threads(numThreads);
    const int antsPerThread = (ant_num + numThreads - 1) / numThreads;

    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int idx = 0; idx < iter; ++idx){
        if (verbose && (idx % 100 == 0))
            cout << "Current Iteration : " << idx << endl;
        double curDist = numeric_limits<double>::infinity();

        for (int t = 0; t < numThreads; ++t) {
            const int startAntIndex = t * antsPerThread;
            const int endAntIndex = min(startAntIndex + antsPerThread, ant_num);
            threads[t] = thread(antColonyOptimizationThread, ref(coords.second), startAntIndex, endAntIndex, alpha, beta, ref(pher), ref(dist), ref(ants));
        }

        // Join threads
        for (int t = 0; t < numThreads; ++t) {
            threads[t].join();
        }
//        Without threading
//        for (Ant &ant : ants){
//            ant.search(alpha, beta, dist, pher);
//            if (ant.TOTAL_DISTANCE < bestDist){
//                bestDist = ant.TOTAL_DISTANCE; bestPath = ant.PATH;
////                if (verbose) cout << "Best Distance : " << bestDist << endl;
//            }
//            if (ant.TOTAL_DISTANCE < curDist) curDist = ant.TOTAL_DISTANCE;
//        }

        for (const Ant& ant : ants) {
            if (ant.TOTAL_DISTANCE < bestDist) {
                bestDist = ant.TOTAL_DISTANCE;
                bestPath = ant.PATH;
            }
            if (ant.TOTAL_DISTANCE < curDist) {
                curDist = ant.TOTAL_DISTANCE;
            }
            // if (ant.TOTAL_DISTANCE < 7542) {
            //     for (int e : ant.PATH) cout << e << " ";
            //     cout << endl;
            // }
        }
        updatePheromone(pher, ants, city_num, rho, q);
    }
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    if (verbose) {
        cout << "Time used : " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds" <<endl;
        cout << "Best Distance : " << bestDist << endl;
    }
    return make_tuple(bestPath, distHistory, bestDist, chrono::duration_cast<chrono::milliseconds>(end - begin).count());
}