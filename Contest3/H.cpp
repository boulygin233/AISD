#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int
BFS(pair<int, int> start, pair<int, int> end, vector<vector<int>> &vertexes_color,
    vector<vector<pair<int, int>>> &vertexes_parent,
    int n, vector<pair<int, int>> horse_way) {
    queue<pair<int, int>> current_vertexes;
    vertexes_color[start.first][start.second] = 1;
    current_vertexes.push(start);
    while (!current_vertexes.empty()) {
        pair<int, int> cur_ver = current_vertexes.front();
        current_vertexes.pop();
        for (int i = 0; i < 8; ++i) {
            if ((cur_ver.first + horse_way[i].first >= 0 && cur_ver.first + horse_way[i].first < n) &&
                (cur_ver.second + horse_way[i].second >= 0 && cur_ver.second + horse_way[i].second < n)) {
                if (!vertexes_color[cur_ver.first + horse_way[i].first][cur_ver.second + horse_way[i].second]) {
                    vertexes_color[cur_ver.first + horse_way[i].first][cur_ver.second + horse_way[i].second] = 1;
                    vertexes_parent[cur_ver.first + horse_way[i].first][cur_ver.second + horse_way[i].second] = cur_ver;
                    current_vertexes.push({cur_ver.first + horse_way[i].first, cur_ver.second + horse_way[i].second});
                    if (cur_ver.first + horse_way[i].first == end.first &&
                        cur_ver.second + horse_way[i].second == end.second) {
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<pair<int, int>> horse_way{{1,  2},
                                     {1,  -2},
                                     {-1, 2},
                                     {-1, -2},
                                     {2,  1},
                                     {2,  -1},
                                     {-2, 1},
                                     {-2, -1}};
    int n;
    cin >> n;
    vector<vector<int>> vertexes_color(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vertexes_color[i].emplace_back(0);
        }
    }
    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    --start.first;
    --start.second;
    --end.first;
    --end.second;
    vector<vector<pair<int, int>>> vertexes_parent;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> a(n);
        vertexes_parent.emplace_back(a);
    }
    vertexes_parent[start.first][start.second] = {-1, -1};
    int k = BFS(start, end, vertexes_color, vertexes_parent, n, horse_way);
    vector<pair<int, int>> way;
    way.emplace_back(end);
    pair<int, int> cur = end;
    while (vertexes_parent[cur.first][cur.second].first != -1) {
        way.emplace_back(vertexes_parent[cur.first][cur.second]);
        cur = vertexes_parent[cur.first][cur.second];
    }
    cout << way.size() - 1 << '\n';
    for (int i = way.size() - 1; i >= 0; --i) {
        cout << way[i].first + 1 << ' ' << way[i].second + 1 << '\n';
    }
}
