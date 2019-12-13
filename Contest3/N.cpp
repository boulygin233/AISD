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

void make_set(int x, vector<int> &representative, vector<int> &size) {
    representative[x] = x;
    size[x] = 1;
}

int find_set(int x, vector<int> &representative) {
    if (x == representative[x]) {
        return x;
    } else {
        return representative[x] = find_set(representative[x], representative);
    }
}

void union_sets(int x, int y, vector<int> &representative, vector<int> &size) {
    x = find_set(x, representative);
    y = find_set(y, representative);
    if (x != y) {
        if (size[x] < size[y]) {
            std::swap(x, y);
        }
        representative[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> graph(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<int> representatives(n);
    vector<int> size(n);
    for (int i = 0; i < n; ++i) {
        make_set(i, representatives, size);
    }
    int bridges = 0;
    for (auto i : edges) {
        ++bridges;
        union_sets(i.first, i.second, representatives, size);
        int x = find_set(0, representatives);
        int check = 0;
        for (int j = 1; j < n; ++j) {
            if (x != find_set(j, representatives)) {
                check = 1;
                break;
            }
        }
        if (check == 0) {
            cout << bridges;
            return 0;
        }
    }
}
