#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::stack;

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

void DFS(int start, vector<Node> &graph, int &is_cycle, stack<int> &cycle) {
    cycle.emplace(start);
    graph[start].set_color(1);
    for (auto i : graph[start].get_neighbours()) {
        if (graph[i].get_color() == 0) {
            DFS(i, graph, is_cycle, cycle);
            if (is_cycle == 1) {
                return;
            }
        }
        if (graph[i].get_color() == 1) {
            cycle.emplace(i);
            is_cycle = 1;
            return;
        }
    }
    graph[start].set_color(2);
    cycle.pop();
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int first_vertex, second_vertex;
        cin >> first_vertex >> second_vertex;
        graph[first_vertex - 1].add_neighbour(second_vertex - 1);
    }


    for (int i = 0; i < n; ++i) {
        if (!graph[i].get_color()) {
            int is_cycle = 0;
            stack<int> cycle;
            graph[i].set_prev(i);
            DFS(i, graph, is_cycle, cycle);
            if (is_cycle == 1) {
                cout << "YES\n";
                int start = cycle.top();
                cycle.pop();
                int size = cycle.size();
                stack<int> result_cycle;
                for (int j = 0; j < size; ++j) {
                    result_cycle.emplace(cycle.top() + 1);
                    if (cycle.top() == start) {
                        break;
                    }
                    cycle.pop();
                }
                size = result_cycle.size();
                for (int j = 0; j < size; ++j) {
                    cout << result_cycle.top() << ' ';
                    result_cycle.pop();
                }
                return 0;
            }
        }
    }
    cout << "NO";
}
