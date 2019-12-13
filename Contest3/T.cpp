#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;


void relax(vector<int> &distances, int u, int v, int w, vector<int> &parents) {
    if (distances[v] > distances[u] + w) {
        distances[v] = distances[u] + w;
        parents[v] = u;
    }
}

void Ford_Bellman(vector<int> &distances, vector<pair<pair<int, int>, int>> &edges, vector<int> &parent) {

    for (int i = 0; i < distances.size() - 1; ++i) {
        for (auto edge: edges) {
            relax(distances, edge.first.first, edge.first.second, edge.second, parent);
        }
    }

    int u, v;
    list<int> cycle;
    for (auto edge: edges) {
        u = edge.first.first;
        v = edge.first.second;
        if (distances[v] > distances[u] + edge.second) {
            parent[v] = u;
            for (int i = 0; i < distances.size(); ++i) {
                v = parent[v];
            }
            u = v;
            v = parent[v];
            if (v == -1) {
                cycle.push_front(u);
            }
            while (u != v) {
                cycle.push_front(v);
                v = parent[v];
            }
            cycle.push_front(v);
            cycle.push_back(v);
            break;
        }
    }
    if (cycle.empty()) {
        cout << "NO";
    } else {
        cout << "YES" << '\n';
        cout << cycle.size() << '\n';
        for (auto i: cycle) {
            cout << i + 1 << ' ';
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> distances(n, 1 << 30);
    distances[0] = 0;
    vector<pair<pair<int, int>, int>> edges;
    vector<int> parent(n, -1);

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            if (w != 100000) {
                edges.emplace_back(make_pair(i, j), w);
            }
        }
    }
    Ford_Bellman(distances, edges, parent);
}
