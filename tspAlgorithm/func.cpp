#include <bits/stdc++.h>
using namespace std;

// vector<pair<double, double>> readTSP(ifstream& in){
//     vector<pair<double, double>> co;
//     int num;
//     in >> num;
//     double idx, cx, cy;
//     while (num--){
//         in >> idx >> cx >> cy;
//         co.emplace_back(make_pair(cx, cy));
//     }
//     return co;
// }

vector<vector<double>> initDist(const vector<pair<double, double>> &coords, const string& type){
    size_t size = coords.size();
    vector<vector<double>> dist(size);
    if (!type.compare("EUC_2D") || !type.compare("CEIL_2D")) {
        for (int i = 0; i < size; i++){
            dist[i] = vector<double> (size);
            double x1 = coords[i].first, y1 = coords[i].second;
            for (int j = 0; j < size; j++){
                double x2 = coords[j].first, y2 = coords[j].second;
                double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                dist[i][j] = d;
            }
        }
    }
    else if (!type.compare("ATT")) {
        for (int i = 0; i < size; i++){
            dist[i] = vector<double> (size);
            double x1 = coords[i].first, y1 = coords[i].second;
            for (int j = 0; j < size; j++){
                double x2 = coords[j].first, y2 = coords[j].second;
                double xd = x1 - x2, yd = y1 - y2;
                double r = sqrt((xd * xd + yd * yd) / 10.0);
                long long t = (long long) (r + 0.5);
                if (t < r) dist[i][j] = ++t;
                else dist[i][j] = t;
            }
        }
    }
    else if (!type.compare("GEO")) {
        double PI = 3.141592;
        double RADIUS = 6378.388;

        for (int i = 0; i < size; i++){
            dist[i] = vector<double> (size);
            double x1 = coords[i].first, y1 = coords[i].second;
            double deg_x1 = (long long) (x1 + 0.5), deg_y1 = (long long) (y1 + 0.5);
            double min_x1 = x1 - deg_x1, min_y1 = y1 - deg_y1;
            double latitude_i = PI * (deg_x1 + 5.0 * min_x1 / 3.0) / 180.0;
            double longitude_i = PI * (deg_y1 + 5.0 * min_y1 / 3.0) / 180.0;
            for (int j = 0; j < size; j++){
                double x2 = coords[j].first, y2 = coords[j].second;
                double deg_x2 = (long long) (x2 + 0.5), deg_y2 = (long long) (y2 + 0.5);
                double min_x2 = x2 - deg_x2, min_y2 = y2 - deg_y2;
                double latitude_j = PI * (deg_x2 + 5.0 * min_x2 / 3.0) / 180.0;
                double longitude_j = PI * (deg_y2 + 5.0 * min_y2 / 3.0) / 180.0;

                double q1 = cos(longitude_i - longitude_j);
                double q2 = cos(latitude_i - latitude_j);
                double q3 = cos(latitude_i + latitude_j);

                dist[i][j] = RADIUS * acos(0.5 * ((1.0 + q1) * q2 - (1.0 - q1) * q3)) + 1.0;

            }
        }
    }
    return dist;
}

pair<string, vector<pair<double, double>>> readTSPData(const string& filename) {
    pair<string, vector<pair<double, double>>> info;
    string line = "";
    int catchType = 0;
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return info;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string keyword;
        ss >> keyword;
        if (keyword.find("EDGE_WEIGHT_TYPE") != string::npos) {
            ss >> info.first;
            if (!info.first.compare(":")) ss >> info.first;
            continue;
        }
        if (keyword == "NODE_COORD_SECTION") {
            while (getline(file, line)) {
                if (line.empty() || line == "EOF") {
                    break;
                }
                stringstream ss_point(line);
                int index;
                double x, y;
                ss_point >> index >> x >> y;
                info.second.push_back({x, y});
            }
        }
    }
    file.close();
    return info;
}

// Test
// int main() {
//     // string filename = "C:/Users/User/Desktop/pybind11 project/ALL_tsp/ali535.tsp";
//     string filename = "C:/Users/User/Desktop/pybind11 project/ALL_tsp/dataset/a280.tsp";
//     pair<string, vector<pair<double, double>>> data = readTSPData(filename);
//     cout << "Size : " << data.second.size() << endl;
//     vector<vector<double>> co = initDist(data.second, data.first);
//     // for (auto v : co) {
//     //     for (auto e : v) {
//     //         cout << e << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // for (auto e : points) cout << e.first << " " << e.second << endl;

// //     // Do further processing with the points data

// //     return 0;
// }










