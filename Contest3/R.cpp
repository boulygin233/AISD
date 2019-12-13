#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::pair;
using std::set;
using std::make_pair;
using std::cin;
using std::cout;


void init(vector<long long> &distances, int n, int s) {
    for (int i = 0; i < n; ++i) {
        distances[i] = (1ll << 62);
    }
    distances[s] = 0;
}

void Dijkstra(int start, vector<long long> &smoke_times, vector<vector<pair<int, int>>> edges) {
    vector<long long> distances(edges.size());
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
    for (int i = 0; i < edges.size(); ++i) {
        smoke_times[i] = std::min(smoke_times[i], distances[i]);
    }
}

void Dijkstra2(int start, vector<long long> &distances, vector<vector<pair<int, int>>> edges) {
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
    std::ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> smoke_stations;
    for (int i = 0; i < k; ++i) {
        int station;
        cin >> station;
        --station;
        smoke_stations.emplace_back(station);
    }
    vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int first, second, weight;
        cin >> first >> second >> weight;
        edges[first - 1].emplace_back(second - 1, weight);
        edges[second - 1].emplace_back(first - 1, weight);
    }
    int start, finish;
    cin >> start >> finish;
    --start;
    --finish;
    vector<long long> smoke_times(n, (1ll << 62));
    for (int i = 0; i < k; ++i) {
        Dijkstra(smoke_stations[i], smoke_times, edges);
    }
    vector<long long> distances(n);
    Dijkstra2(start, distances, edges);
    if (distances[finish] < smoke_times[finish]) {
        cout << distances[finish];
    } else {
        cout << -1;
    }
}
