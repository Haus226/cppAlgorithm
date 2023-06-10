#include <bits/stdc++.h>
#include "func.hpp"
#include "geneticAlgorithm.hpp"
using namespace std;

vector<vector<int>> initPopulation(long long int popSize, const vector<int> &order){
    vector<vector<int>> population(popSize);
    for (int cnt = 0; cnt < popSize; cnt++){
        vector<int> newIndividual = order;
        shuffle(newIndividual.begin(), newIndividual.end(), random_device());
        population[cnt] = newIndividual;
    }
    return population;
}

double calFitness(const vector<int> &order, const vector<vector<double>> &dist){
    size_t length = order.size();
    double distSum = 0;
    for (int idx = 0; idx < length - 1; idx++) distSum += dist[order[idx]][order[idx + 1]];
    distSum += dist[order[length - 1]][order[0]];
    return 1 / distSum;
}

vector<pair<int, double>> ranking(const vector<vector<int>> &population, const vector<vector<double>> &dist){
    size_t size = population.size();
    vector<pair<int, double>> fitness(size);
    for(int idx = 0; idx < size; idx++) fitness[idx] = make_pair(idx, calFitness(population[idx], dist));
    sort(fitness.begin(), fitness.end(),
            // Lambda function to sort in descending order based on second element
         [](const pair<int, double> &x, const pair<int, double> &y){
             return (x.second > y.second);
         });
    return fitness;
}

vector<int> selection(const int &eliteSize, const vector<pair<int, double>> &ranking){
    size_t length = ranking.size();
    vector<int> selection_;
    selection_.reserve(length);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    uniform_int_distribution<int> idxDistribution(0, length - 1);
    for(int cnt = 0; cnt < eliteSize; cnt++) selection_.push_back(ranking[cnt].first);
    while (selection_.size() < length){
        if (distribution(gen) > 0.5){
            selection_.push_back(ranking[idxDistribution(gen)].first);
        }
    }
    return selection_;
}

vector<vector<int>> mating(const vector<vector<int>> &population, const vector<int> &selection){
    size_t length = selection.size();
    vector<vector<int>> pool(length);
    for (int cnt = 0; cnt < length; cnt++) pool[cnt] = population[selection[cnt]];
    return pool;
}

vector<int> breed(const vector<int> &parent1, const vector<int> &parent2){
    vector<int> childP1, childP2;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    int GeneA = (int)(distribution(gen) * parent1.size());
    int GeneB = (int)(distribution(gen) * parent1.size());
    int startGene = min(GeneA, GeneB);
    int endGene = max(GeneA, GeneB);
    for(int idx = startGene; idx < endGene; idx++) childP1.push_back(parent1[idx]);
    for(int idx : parent2){
        if (find(childP1.begin(), childP1.end(), idx) == childP1.end()) childP2.push_back(idx);
    }
    childP1.insert(childP1.end(), childP2.begin(), childP2.end());
    return childP1;
}

vector<vector<int>> breedPopulation(const int &eliteSize, vector<vector<int>> &matingPool){
    vector<vector<int>> children;
    children.reserve(matingPool.size());
    size_t length = matingPool.size() - eliteSize;
    for (int idx = 0; idx < eliteSize; idx++) children.push_back(matingPool[idx]);
    shuffle(matingPool.begin(), matingPool.end(), random_device());
    for (int idx = 0; idx < length; idx ++)
        children.push_back(breed(matingPool[idx], matingPool[matingPool.size() - idx - 1]));
    return children;
}

void mutate(const double &mutateRate, vector<int> &individual){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    uniform_int_distribution<> intDistribution(0, individual.size() - 1);
    for (int cnt = 0; cnt < individual.size(); cnt++){
        if (distribution(gen) < mutateRate){
            int x = intDistribution(gen), y = intDistribution(gen);
            swap(individual[x], individual[y]);
        }
    }
}

void mutatePopulation(vector<vector<int>> &population, const double &mutateRate){
    for (vector<int> idx : population) mutate(mutateRate, idx);

}

vector<vector<int>> nextGen(const vector<vector<int>> &curPop,
                            const vector<vector<double>> &initDistance,
                            const int& eliteSize, const double &mutateRate
){
    vector<pair<int, double>> ranking_ = ranking(curPop, initDistance);
    vector<int> selection_ = selection(eliteSize, ranking_);
    vector<vector<int>> mating_ = mating(curPop, selection_);
    vector<vector<int>> children_ = breedPopulation(eliteSize, mating_);
    mutatePopulation(children_, mutateRate);
    return children_;
}

tuple<vector<int>, vector<double>, double, long long> geneticAlgorithm(const pair<string, vector<pair<double, double>>> &coords,
                                                                       const int &iterations, const double &mutateRate,
                                                                       const int &popSize, const int &eliteSize, const bool &verbose) {
    vector<int> initOrder(coords.second.size());
    for (int idx = 0; idx < coords.second.size(); idx++) initOrder[idx] = idx;
    vector<vector<int>> pop = initPopulation(popSize, initOrder);
    vector<vector<double>> dist = initDist(coords.second, coords.first);
    double curDist = 1 / (ranking(pop, dist)[0].second);
    double bestDist = curDist;
    vector<int> bestOrder;
    vector<double> distHistory(iterations);
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int cnt = 0; cnt < iterations; cnt++){
        if (verbose && (cnt % 100 == 0)) cout << "Current Iteration : " << cnt << endl;
        distHistory[cnt] = curDist;
        pop = nextGen(pop, dist, eliteSize, mutateRate);
        pair<int, double> cur = ranking(pop, dist)[0];
        curDist = 1 / cur.second;
        if (curDist < bestDist) {
            bestDist = curDist;
            bestOrder = pop[cur.first];
        }
    }
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    if (verbose) {
        cout << "Time used : " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds" <<endl;
        cout << "Best Distance : " << bestDist << endl;
    }
    return make_tuple(bestOrder, distHistory, bestDist, chrono::duration_cast<chrono::milliseconds>(end - begin).count());
}


tuple<vector<vector<int>>, vector<vector<double>>, vector<double>, vector<long long>> 
threadedGeneticAlgorithm(const pair<string, vector<pair<double, double>>> &coords, const int &iterations, const double &mutateRate,
                         const int &popSize, const int &eliteSize, const bool &verbose, int numThreads) {
    if (!numThreads) numThreads = thread::hardware_concurrency();
    // cout << "Num of Threads : " << numThreads << endl;
    // numThreads -= 10;
    vector<thread> threads;
    vector<vector<int>> bestOrders(numThreads);
    vector<vector<double>> distHistories(numThreads);
    vector<double> bestDists(numThreads);
    vector<long long> timeTaken(numThreads);

    for (int t = 0; t < numThreads; t++) {
        threads.emplace_back([t, &coords, iterations, mutateRate, popSize, eliteSize, verbose, &bestOrders, &distHistories, &bestDists, &timeTaken]() {
            auto [bestOrder, distHistory, bestDist, duration] = geneticAlgorithm(coords, iterations, mutateRate,
                                                                                 popSize, eliteSize, verbose);
            bestOrders[t] = bestOrder;
            distHistories[t] = distHistory;
            bestDists[t] = bestDist;
            timeTaken[t] = duration;
        });
    }

    for (auto &thread : threads) {
        thread.join();
    }

    // Process results
    double overallBestDist = numeric_limits<double>::max();
    vector<int> overallBestOrder;
    long long overallTimeTaken = 0;

    for (int t = 0; t < numThreads; t++) {
        if (bestDists[t] < overallBestDist) {
            overallBestDist = bestDists[t];
            overallBestOrder = bestOrders[t];
        }
        overallTimeTaken += timeTaken[t];
    }
    if (verbose) {
        cout << "Overall Best Distance : " << overallBestDist << endl;
        cout << "Overall Time Taken : " << overallTimeTaken << " milliseconds" << endl;
    }
    return make_tuple(bestOrders, distHistories, bestDists, timeTaken);

}





