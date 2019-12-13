#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Node {
private:
    int num;
    int color;
    int time;
    int component;
    std::vector<int> neighbours;
public:
    Node() {
        static int k = 0;
        color = 0;
        num = k;
        time = 0;
        component = 0;
        ++k;
    }

    Node(int n) {
        static int k = 0;
        color = 0;
        num = k;
        time = 0;
        component = 0;
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

    int get_component() {
        return component;
    }

    void set_component(int new_component) {
        component = new_component;
    }

    void set_color(int new_color) {
        color = new_color;
    }

    void set_time(int new_time) {
        time = new_time;
    }

    void add_neighbour(int neighbour) {
        neighbours.emplace_back(neighbour);
    }

    std::vector<int> get_neighbours() {
        return neighbours;
    }
};


void DFS(int start_vertex, std::vector<Node> &graph, int &time) {
    graph[start_vertex].set_color(1);
    for (auto i : graph[start_vertex].get_neighbours()) {
        if (graph[i].get_color() == 0) {
            DFS(i, graph, time);
        }
    }
    graph[start_vertex].set_time(time);
    ++time;
}

void DFS2(int start_vertex, std::vector<Node> &graph2, int current) {
    graph2[start_vertex].set_color(1);
    graph2[start_vertex].set_component(current);
    for (auto i : graph2[start_vertex].get_neighbours()) {
        if (!graph2[i].get_color()) {
            DFS2(i, graph2, current);
        }
    }
}

bool cmp(Node A, Node B) {
    return (A.get_time() >= B.get_time()) ? true : false;
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
    for (int i = 0; i < n; ++i) {
        if (!graph[i].get_color()) {
            DFS(i, graph, time);
        }
    }
    std::vector<Node> graph2(n, Node(n));
    for (auto i : graph) {
        for (auto j : i.get_neighbours()) {
            graph2[j].add_neighbour(i.get_num());
        }
    }
    std::sort(graph.begin(), graph.end(), &cmp);
    int current = 1;
    for (auto i : graph) {
        if (!graph2[i.get_num()].get_color()) {
            DFS2(i.get_num(), graph2, current);
            ++current;
        }
    }
    std::cout << current - 1 << '\n';
    for (auto i : graph2) {
        std::cout << i.get_component() << ' ';
    }

}
