#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<int> &times, int n, int s) {
    for (int i = 0; i < n; ++i) {
        times[i] = 1000000001;
    }
    times[s] = 0;
}

void relax(pair<pair<int, int>, pair<int, int>> flight, vector<int> &times) {
    if (flight.second.first >= times[flight.first.first] && flight.second.second < times[flight.first.second]) {
        times[flight.first.second] = flight.second.second;
    }
}

void Ford_Bellman(const vector<pair<pair<int, int>, pair<int, int>>> &flights, int start, int n, vector<int> &times) {
    init(times, n, start);
    for (int i = 0; i < flights.size(); ++i) {
        for (auto j : flights) {
            if (times[j.first.first] != 1000000001 || times[j.first.second] != 1000000001) {
                relax(j, times);
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n;
    int start, finish;
    cin >> start >> finish;
    vector<int> times(n);
    cin >> m;
    vector<pair<pair<int, int>, pair<int, int>>> flights(m);
    for (int i = 0; i < m; ++i) {
        cin >> flights[i].first.first >> flights[i].second.first >> flights[i].first.second >> flights[i].second.second;
        --flights[i].first.first;
        --flights[i].first.second;
    }
    Ford_Bellman(flights, start - 1, n, times);
    cout << times[finish - 1];
}
