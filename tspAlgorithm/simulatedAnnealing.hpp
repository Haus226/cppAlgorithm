#include <bits/stdc++.h>
#include "func.hpp"
using namespace std;


double calDist(const vector<int> &order, const vector<vector<double>> &dist);

vector<int> nextOrder_(const vector<int>preOrder, mt19937 gen);

tuple<vector<int>, vector<double>, double, long long> simulatedAnnealing(const pair<string, vector<pair<double, double>>>& co,
                               double startTemp = 10000,
                               double endTemp = 0.0001,
                               double coolingRate = 0.999,
                               const bool &verbose=false);




