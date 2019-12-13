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
    int rep_x = find_set(x, representative);
    int rep_y = find_set(y, representative);
    if (rep_x != rep_y) {
        if (size[rep_x] < size[rep_y]) {
            std::swap(rep_x, rep_y);
        }
        representative[rep_y] = rep_x;
        size[rep_x] += size[rep_y];
    }
}

bool cmp(pair<pair<int, int>, long long> A, pair<pair<int, int>, long long> B) {
    return A.second <= B.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> representatives(n);
    vector<int> size(n);
    for (int i = 0; i < n; ++i) {
        make_set(i, representatives, size);
    }
    vector<pair<pair<int, int>, long long>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }
    long long min_weight = 0;
    std::sort(edges.begin(), edges.end(), &cmp);
    for (auto i : edges) {
        if (find_set(i.first.first - 1, representatives) != find_set(i.first.second - 1, representatives)) {
            min_weight += i.second;
            union_sets(i.first.first - 1, i.first.second - 1, representatives, size);
        }
    }
    cout << min_weight;
}
