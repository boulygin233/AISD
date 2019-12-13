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

int get_weight(int x, vector<int> &representative, vector<int> &weights) {
    if (x == representative[x]) {
        return weights[x];
    } else {
        return weights[x] = weights[find_set(representative[x], representative)];
    }
}

void union_sets(int x, int y, vector<int> &representative, vector<int> &size, vector<int> &weights, int weight) {
    int rep_x = find_set(x, representative);
    int rep_y = find_set(y, representative);
    if (rep_x != rep_y) {
        if (size[rep_x] < size[rep_y]) {
            std::swap(rep_x, rep_y);
        }
        weights[rep_x] += weights[rep_y];
        representative[rep_y] = rep_x;
        size[rep_x] += size[rep_y];
    }
    weights[rep_x] += weight;
    weights[x] = weights[y] = weights[rep_x];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> representatives(n);
    vector<int> size(n);
    for (int i = 0; i < n; ++i) {
        make_set(i, representatives, size);
    }
    vector<int> weights(n, 0);
    int code;
    for (int i = 0; i < m; ++i) {
        cin >> code;
        if (code == 1) {
            int first_vertex, second_vertex, weight;
            cin >> first_vertex >> second_vertex >> weight;
            union_sets(first_vertex - 1, second_vertex - 1, representatives, size, weights, weight);
        } else {
            int vertex;
            cin >> vertex;
            cout << weights[find_set(vertex - 1, representatives)] << '\n';
        }
    }
}
