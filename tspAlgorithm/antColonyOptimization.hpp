#include <bits/stdc++.h>
#include "func.hpp"
using namespace std;

class Ant {
    private:
        size_t CITY_NUM = 0;
        int MOVE_CNT = 0;
        int CURRENT_CITY;
        vector<bool> VISITED;

        void clean();

        void next(const double &ALPHA, const double &BETA,
                const vector<vector<double>> &DIST,
                const vector<vector<double>> &PHER);
    public:
        double TOTAL_DISTANCE = 0;
        vector<int> PATH;
        explicit Ant(const size_t &NUM);
        void search(const double &ALPHA, const double &BETA,
                    const vector<vector<double>> &DIST,
                    const vector<vector<double>> &PHER);
};

void updatePheromone(vector<vector<double>> &pher,
                     const vector<Ant> &ants, const size_t &num,
                     const double &rho, const double &q);


tuple<vector<int>, vector<double>, double, long long> antColonyOptimization(const pair<string, vector<pair<double, double>>> &coords, const int &ant_num,
                                                       const double &alpha, const double &beta,
                                                       const double &tau, const double &rho,
                                                       const double &q, const int &iter,
                                                       const bool &verbose, int numThreads = 0);

void antColonyOptimizationThread(const vector<pair<double, double>>& coords, const int startAntIndex, const int endAntIndex, const double alpha, const double beta, vector<vector<double>>& pher, vector<vector<double>>& dist, vector<Ant>& ants);
 