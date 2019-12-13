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
    return A.second < B.second;
}

int main() {
    int n;
    cin >> n;
    vector<int> representatives(n + 1);
    vector<int> size(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        make_set(i, representatives, size);
    }
    vector<pair<pair<int, int>, long long>> edges;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            long long cost;
            cin>>cost;
            if (i > j) {
                edges.emplace_back(std::make_pair(i, j), cost);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        long long cost;
        cin>>cost;
        edges.emplace_back(std::make_pair(i, n), cost);
    }
    long long min_weight = 0;
    std::sort(edges.begin(), edges.end(), &cmp);
    for (auto i : edges) {
        if (find_set(i.first.first, representatives) != find_set(i.first.second, representatives)) {
            min_weight += i.second;
            union_sets(i.first.first, i.first.second, representatives, size);
        }
    }
    cout << min_weight;
}
