#include <bits/stdc++.h>
#include "func.hpp"
using namespace std;

vector<vector<int>> initPopulation(long long int popSize, const vector<int> &order);


double calFitness(const vector<int> &order, const vector<vector<double>> &dist);

vector<pair<int, double>> ranking(const vector<vector<int>> &population, const vector<vector<double>> &dist);

vector<int> selection(const int &eliteSize, const vector<pair<int, double>> &ranking);

vector<vector<int>> mating(const vector<vector<int>> &population, const vector<int> &selection);

vector<int> breed(const vector<int> &parent1, const vector<int> &parent2);

vector<vector<int>> breedPopulation(const int &eliteSize, vector<vector<int>> &matingPool);

void mutate(const double &mutateRate, vector<int> &individual);

void mutatePopulation(vector<vector<int>> &population, const double &mutateRate);

vector<vector<int>> nextGen(const vector<vector<int>> &curPop, 
            const vector<vector<double>> &initDistance, 
            const int& eliteSize, const double &mutateRate);

tuple<vector<int>, vector<double>, double, long long> geneticAlgorithm(const pair<string, vector<pair<double, double>>> &coords,
                      const int &iterations, const double &mutateRate, 
                      const int &popSize, const int &eliteSize, const bool &verbose);

tuple<vector<vector<int>>, vector<vector<double>>, vector<double>, vector<long long>> 
threadedGeneticAlgorithm(const pair<string, vector<pair<double, double>>> &coords, const int &iterations, const double &mutateRate,
                         const int &popSize, const int &eliteSize, const bool &verbose, int numThreads = 0);
 

