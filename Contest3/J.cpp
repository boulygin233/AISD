#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::stack;
using std::queue;
using std::pair;

class Node {
private:
    int num;
    int color;
    int prev;
    vector<int> neighbours;
public:
    Node() {
        static int k = 0;
        color = 0;
        num = k;
        prev = num;
        ++k;
    }

    int get_color() {
        return color;
    }

    int get_num() {
        return num;
    }

    int get_prev() {
        return prev;
    }

    void set_color(int new_color) {
        color = new_color;
    }

    void set_prev(int new_prev) {
        prev = new_prev;
    }


    void add_neighbour(int neighbour) {
        neighbours.emplace_back(neighbour);
    }

    std::vector<int> get_neighbours() {
        return neighbours;
    }
};

/*void BFS(pair<int, int> coordinate, vector<vector<int>> &table, int n, int m, vector<pair<int, int>> steps) {
    queue<pair<int, int>> current_queue;
    current_queue.emplace(coordinate);
    table[coordinate.first][coordinate.second] = 0;
    while (!current_queue.empty()) {
        pair<int, int> cur_cell = current_queue.front();
        current_queue.pop();
        for (auto & step : steps) {
            if (cur_cell.first + step.first >= 0 && cur_cell.first + step.first < n &&
                cur_cell.second + step.second >= 0 && cur_cell.second + step.second <= m) {
                if (table[cur_cell.first + step.first][cur_cell.second + step.second] >
                    table[cur_cell.first][cur_cell.second] + 1) {
                    table[cur_cell.first + step.first][cur_cell.second + step.second] =
                            table[cur_cell.first][cur_cell.second] + 1;
                    current_queue.emplace(cur_cell.first + step.first, cur_cell.second + step.second);
                }
            }
        }
    }
}*/

int main() {
    int n, m;
    vector<pair<int, int >> steps{{1,  0},
                                  {0,  1},
                                  {-1, 0},
                                  {0,  -1}};
    cin >> n >> m;
    vector<pair<int, int>> one_coordinates;
    vector<vector<int>> table(n, vector<int>(m, 1000));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            if (num) {
                one_coordinates.emplace_back(i, j);
            }
        }
    }
    for (auto i : one_coordinates) {
        for (int j = 0; j < n; ++j){
            for (int k = 0; k < m ; ++k){
                if (table[j][k] > (abs(i.first - j) + abs(i.second - k))){
                    table[j][k] = abs(i.first - j) + abs(i.second - k);
                }
            }
        }
    }
    for (auto i : table) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
