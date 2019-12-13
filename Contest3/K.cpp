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

struct new_coord {
    int up;
    int down;
    int left;
    int right;
};

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

void
BFS(pair<int, int> start, pair<int, int> finish, vector<vector<new_coord>> new_coords, vector<vector<int>> &presses) {
    queue<pair<int, int>> current_queue;
    current_queue.emplace(start);
    presses[start.first][start.second] = 0;
    while (!current_queue.empty()) {
        pair<int, int> cur_cell = current_queue.front();
        current_queue.pop();
        if (presses[cur_cell.first][new_coords[cur_cell.first][cur_cell.second].left] >
            presses[cur_cell.first][cur_cell.second] + 1) {
            presses[cur_cell.first][new_coords[cur_cell.first][cur_cell.second].left] =
                    presses[cur_cell.first][cur_cell.second] + 1;
            current_queue.emplace(cur_cell.first, new_coords[cur_cell.first][cur_cell.second].left);
        }
        if (presses[cur_cell.first][new_coords[cur_cell.first][cur_cell.second].right] >
            presses[cur_cell.first][cur_cell.second] + 1) {
            presses[cur_cell.first][new_coords[cur_cell.first][cur_cell.second].right] =
                    presses[cur_cell.first][cur_cell.second] + 1;
            current_queue.emplace(cur_cell.first, new_coords[cur_cell.first][cur_cell.second].right);
        }
        if (presses[new_coords[cur_cell.first][cur_cell.second].up][cur_cell.second] >
            presses[cur_cell.first][cur_cell.second] + 1) {
            presses[new_coords[cur_cell.first][cur_cell.second].up][cur_cell.second] =
                    presses[cur_cell.first][cur_cell.second] + 1;
            current_queue.emplace(new_coords[cur_cell.first][cur_cell.second].up, cur_cell.second);
        }
        if (presses[new_coords[cur_cell.first][cur_cell.second].down][cur_cell.second] >
            presses[cur_cell.first][cur_cell.second] + 1) {
            presses[new_coords[cur_cell.first][cur_cell.second].down][cur_cell.second] =
                    presses[cur_cell.first][cur_cell.second] + 1;
            current_queue.emplace(new_coords[cur_cell.first][cur_cell.second].down, cur_cell.second);
        }
        if (cur_cell == finish) {
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> start, finish;
    vector<vector<char >> track(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> track[i][j];
            if (track[i][j] == 'S') {
                start = {i, j};
            }
            if (track[i][j] == 'T') {
                finish = {i, j};
            }
        }
    }
    vector<vector<new_coord>> new_coords(n, vector<new_coord>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (track[i][j] == '#') {
                new_coords[i][j].down = -1;
                new_coords[i][j].left = -1;
                new_coords[i][j].up = -1;
                new_coords[i][j].right = -1;
            } else {
                int x = j;
                while (x < m && track[i][x] != '#') {
                    ++x;
                }
                new_coords[i][j].right = j + (x - j - 1) / 2 + (x - j - 1) % 2;
                x = j;
                while (x >= 0 && track[i][x] != '#') {
                    --x;
                }
                new_coords[i][j].left = j - (j - x - 1) / 2 - (j - x - 1) % 2;
                x = i;
                while (x >= 0 && track[x][j] != '#') {
                    --x;
                }
                new_coords[i][j].up = i - (i - x - 1) / 2 - (i - x - 1) % 2;
                x = i;
                while (x < n && track[x][j] != '#') {
                    ++x;
                }
                new_coords[i][j].down = i + (x - i - 1) / 2 + (x - i - 1) % 2;
            }
        }
    }
    vector<vector<int>> presses(n, vector<int>(m, 1000));
    BFS(start, finish, new_coords, presses);
    if (presses[finish.first][finish.second] == 1000) {
        cout << -1;
    } else {
        cout << presses[finish.first][finish.second];
    }
}
