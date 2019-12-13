#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<int>&distances, int n, int s){
    for (int i = 0; i < n; ++i){
        distances[i] = 30000;
    }
    distances[s] = 0;
}

void relax(int u, int v, int w, vector<int>&distances){
    distances[v] = min(distances[v], distances[u] + w);
}

void Ford_Bellman (const vector<pair<pair<int, int>, int>>& edges, int start, int n, vector<int>&distances){
    init(distances, n, start);
    for (int i = 1; i < n - 1; ++i){
        for (auto j : edges){
            if (distances[j.first.second] != 30000 ||distances[j.first.first] != 30000){
                relax(j.first.first, j.first.second, j.second, distances);
            }
        }
    }
}


int main() {
    int n, m;
    cin>>n>>m;
    vector<int>distances(n);
    vector<pair<pair<int, int>, int>> edges(m);
    for(int i = 0; i < m; ++i){
        cin>>edges[i].first.first>>edges[i].first.second>>edges[i].second;
        --edges[i].first.first;
        --edges[i].first.second;
    }
    Ford_Bellman(edges, 0, n, distances);
    for (auto i : distances){
        cout<<i<<' ';
    }
}
