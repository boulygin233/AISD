#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void init(vector<long long> &distances, int n, int s) {
    for (int i = 0; i < n; ++i) {
        distances[i] = 2009000999;
    }
    distances[s] = 0;
}

void Dijkstra(int start, vector<long long> &distances, vector<vector<pair<int, int>>> edges) {
    init(distances, edges.size(), start);
    set<pair<long long, int>> current_set;
    for (int i = 0; i < edges.size(); ++i) {
        current_set.insert(make_pair(distances[i], i));
    }
    while (!current_set.empty()) {
        pair<long long, int> current_vertex = *current_set.begin();
        current_set.erase(current_set.begin());
        for (int i = 0; i < edges[current_vertex.second].size(); ++i) {
            if (distances[edges[current_vertex.second][i].first] >
                current_vertex.first + edges[current_vertex.second][i].second) {
                current_set.erase(make_pair(distances[edges[current_vertex.second][i].first],
                                            edges[current_vertex.second][i].first));
                distances[edges[current_vertex.second][i].first] =
                        current_vertex.first + edges[current_vertex.second][i].second;
                current_set.insert(make_pair(distances[edges[current_vertex.second][i].first],
                                             edges[current_vertex.second][i].first));
            }
        }
    }
}

int main() {
    int NUM;
    cin >> NUM;
    for (int k = 0; k < NUM; ++k) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
        for (int i = 0; i < m; ++i) {
            int first, second, weight;
            cin >> first >> second >> weight;
            edges[first].emplace_back(second, weight);
            edges[second].emplace_back(first, weight);
        }
        int start;
        cin >> start;
        vector<long long> distances(n);
        Dijkstra(start, distances, edges);
        for (auto j : distances) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
