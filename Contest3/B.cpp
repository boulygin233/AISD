#include <iostream>
#include <vector>
#include <queue>

class Node {
private:
    int num;
    int color;
    std::vector<int> neighbours;
public:
    Node() {
        static int k = 0;
        color = 0;
        num = k;
        ++k;
    }

    int get_color() {
        return color;
    }

    int get_num() {
        return num;
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

int BFS(int start_vertex, std::vector<Node> &graph) {
    std::queue<int> current_queue;
    current_queue.emplace(start_vertex);
    while (!current_queue.empty()) {
        int current_vertex = current_queue.front();
        current_queue.pop();
        for (auto i : graph[current_vertex].get_neighbours()) {
            if (graph[i].get_color() == 0) {
                graph[i].set_color(-graph[current_vertex].get_color());
                current_queue.emplace(i);
            } else if (graph[i].get_color() == graph[current_vertex].get_color()) {
                return 0;
            }
        }
    }
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
        graph[second_vertex - 1].add_neighbour(first_vertex - 1);
    }
    for (auto i : graph) {
        if (i.get_color() == 0) {
            graph[i.get_num()].set_color(1);
            if (BFS(i.get_num(), graph) == 0) {
                std::cout << "NO";
                return 0;
            }
        }
    }
    std::cout << "YES";
}
