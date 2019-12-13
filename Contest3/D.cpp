#include <iostream>
#include <vector>
#include <algorithm>

class Node {
private:
    int num;
    int color;
    std::vector<int> neighbours;
    int time;
public:
    Node() {
        static int k = 0;
        color = 0;
        num = k;
        time = 0;
        ++k;
    }

    int get_color() {
        return color;
    }

    int get_num() {
        return num;
    }

    int get_time() {
        return time;
    }

    int set_time(int new_time) {
        time = new_time;
    }

    void set_color(int new_color) {
        color = new_color;
    }

    void add_neighbour(int neighbour) {
        neighbours.emplace_back(neighbour);
    }

    std::vector<int> get_neighbours() {
        return neighbours;
    }
};

bool cmp(Node A, Node B) {
    return A.get_time() >= B.get_time() ? true : false;
}

int DFS(int start_vertex, std::vector<Node> &graph, int &time) {
    graph[start_vertex].set_color(1);
    for (auto i : graph[start_vertex].get_neighbours()) {
        if (graph[i].get_color() == 0) {
            int checker = DFS(i, graph, time);
            if (!checker) {
                return 0;
            }
        } else if (graph[i].get_color() == 1) {
            return 0;
        }
    }
    graph[start_vertex].set_color(2);
    graph[start_vertex].set_time(time);
    ++time;
    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int first_vertex, second_vertex;
        std::cin >> first_vertex >> second_vertex;
        graph[first_vertex - 1].add_neighbour(second_vertex - 1);
    }
    int time = 0;
    for (auto i : graph) {
        if (i.get_color() == 0) {
            std::vector<int> current_component;
            if (!DFS(i.get_num(), graph, time)) {
                std::cout << -1;
                return 0;
            }
        }
    }
    std::sort(graph.begin(), graph.end(), &cmp);
    for (auto i : graph) {
        std::cout << i.get_num() + 1 << ' ';
    }
}
