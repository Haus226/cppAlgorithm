#pragma once
#include <bits/stdc++.h>
using namespace std;

pair<string, vector<pair<double, double>>> readTSPData(const string& filename);

vector<vector<double>> initDist(const vector<pair<double, double>> &coords, const string& type);