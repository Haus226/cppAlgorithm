#include "bits/stdc++.h"
#include "antColonyOptimization.hpp"
#include "geneticAlgorithm.hpp"
#include "simulatedAnnealing.hpp"
#include "func.hpp"

int main(int argc, char * argv[]) {

    string file(argv[1]);
    replace(file.begin(), file.end(), '\\', '/');
    // string file("C:/Users/User/Desktop/pybind11 project/ALL_tsp/dataset/burma14.tsp");

    pair<string, vector<pair<double, double>>> co = readTSPData(file);
    
    tuple<vector<int>, vector<double>, double, long long> p = antColonyOptimization(co, co.second.size() * 1 / 5, 5, 10, 1, 0.9, 1, 1000, true, 6);
    vector<int> v = get<0>(p);
    // for (int e : v) cout << e << " ";

    cout << endl;
    
    p = geneticAlgorithm(co, 2000, 0.1, 5000, 1000, true);
    v = get<0>(p);
    // for (int e : v) cout << e << " ";

    cout << endl;

    p = simulatedAnnealing(co, 100000, 0.00001, 0.9999, true);


    // tuple<vector<vector<int>>, vector<vector<double>>, vector<double>, vector<long long>> t = threadedGeneticAlgorithm(co, 1000, 0.1, 1000, 200, true, 4);
    // vector<double> bestDist = get<2>(t);
    // int min = 0;
    // for (int i = 0; i < bestDist.size(); i++) {
    //     if (bestDist[min] > bestDist[i]) min = i;
    // }


    // vector<vector<int>> bestOrders = get<0>(t);
    // cout << "Best Dist : " << bestDist[min] << endl;
    // for (int e : bestOrders[min]) cout << e << " ";
}
