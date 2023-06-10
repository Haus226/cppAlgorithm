#include <bits/stdc++.h>
#include "func.hpp"
#include "simulatedAnnealing.hpp"
using namespace std;


double calDist(const vector<int> &order, const vector<vector<double>> &dist){
    double distSum = 0;
    for (int idx = 0; idx < order.size() - 1; idx++) distSum += dist[order[idx]][order[idx + 1]];
    distSum += dist[order[order.size() - 1]][order[0]];
    return distSum;
}

vector<int> nextOrder_(const vector<int>preOrder, mt19937 gen){
    uniform_int_distribution<> intDistribution_1(0, preOrder.size() - 1);
    vector<int> nextOrder = preOrder;
    // Generate random integer 0 or 1
    int num = rand() % 2;
    if (num){
        int idx = intDistribution_1(gen);
        uniform_int_distribution<> intDistribution_2(idx, preOrder.size() - 1); // define the range
        int jdx = intDistribution_2(gen);
        while (jdx > idx){
            swap(nextOrder[idx], nextOrder[jdx]);
            idx++; jdx--;
        }
    }
    else {
        int idx = intDistribution_1(gen);
        int jdx = intDistribution_1(gen);
        swap(nextOrder[idx], nextOrder[jdx]);
    }
    return nextOrder;
}


tuple<vector<int>, vector<double>, double, long long> simulatedAnnealing(const pair<string, vector<pair<double, double>>>& co,
                               double startTemp,
                               double endTemp,
                               double coolingRate,
                               const bool &verbose) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_real_distribution<double> distribution(0.0, 1.0);
    size_t size = co.second.size();
    vector<vector<double>> dist = initDist(co.second, co.first);
    
    vector<int> curOrder(size), bestOrder(size);
    for (int idx=0; idx < size; idx++) curOrder[idx] = idx;
    double curDist = calDist(curOrder, dist);
    double bestDist = curDist;
    double curTemp = startTemp;
    vector<double> distHistory;
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    while (curTemp > endTemp){
        distHistory.emplace_back(curDist);
        vector<int> nextOrder = nextOrder_(curOrder, gen);
        double nextDist = calDist(nextOrder, dist);
        double delta = nextDist - curDist;
        if (delta < 0){
            curOrder = nextOrder;
            curDist = nextDist;
        }
        else{
            double tol = distribution(gen);
            if (exp(-delta / curTemp) > tol) {
                curOrder = nextOrder;
                curDist = nextDist;
            }
        }
        if (curDist < bestDist) {
            bestDist = curDist;
            bestOrder = curOrder;
            }
        curTemp *= coolingRate;
    }
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    if (verbose) {
        cout << "Time used : " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds" <<endl;
        cout << "Best Distance : " << bestDist << endl;
    }
    return make_tuple(bestOrder, distHistory, bestDist, chrono::duration_cast<chrono::milliseconds>(end - begin).count());
}



