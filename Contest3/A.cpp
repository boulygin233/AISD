#include <iostream>
#include <vector>

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

    int get_num(){
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

void DFS(int start_vertex, std::vector<Node> &graph, std::vector<int> &current_component) {
    graph[start_vertex].set_color(1);
    current_component.emplace_back(start_vertex);
    for (auto i : graph[start_vertex].get_neighbours()) {
        if (graph[i].get_color() == 0) {
            DFS(i, graph, current_component);
        }
    }
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
    std::vector<std::vector<int>> components;
    for (auto i : graph){
        if (i.get_color() == 0){
            std::vector<int>current_component;
            DFS(i.get_num(), graph, current_component);
            components.emplace_back(current_component);
        }
    }
    std::cout<<components.size()<<'\n';
    for(auto i : components){
        std::cout<<i.size()<<'\n';
        for (auto j : i) {
            std::cout<<j + 1<<' ';
        }
        std::cout<<'\n';
    }
}
