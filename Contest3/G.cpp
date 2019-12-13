#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


class Node {
private:
    int num;
    int color;
    int prev;
    std::vector<int> neighbours;
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

/*int BFS(int start, int finish, vector<vector<int>>edges, vector<int>&vertexes_color, vector<int>&vertexes_parent, int n){
    queue<int> current_vertexes;
    vertexes_color[start] = 1;
    current_vertexes.push(start);
    while (!current_vertexes.empty()){
        int cur_ver = current_vertexes.front();
        current_vertexes.pop();
        for (int i = 0; i < n; ++i){
            if (edges[cur_ver][i]){
                if (!vertexes_color[i]){
                    vertexes_color[i] = 1;
                    vertexes_parent[i] = cur_ver;
                    current_vertexes.push(i);
                    if (i == finish){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}*/

int BFS(int start, int finish, std::vector<Node>&graph) {
    std::queue<int>current_queue;
    graph[start].set_color(1);
    current_queue.emplace(start);
    while (!current_queue.empty()){
        int current_vertex = current_queue.front();
        current_queue.pop();
        for (auto i : graph[current_vertex].get_neighbours()){
            if (!graph[i].get_color()){
                graph[i].set_color(1);
                graph[i].set_prev(current_vertex);
                current_queue.emplace(i);
                if (i == finish) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int start_vertex, finish_vertex;
    std::cin >> start_vertex >> finish_vertex;
    std::vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int first_vertex, second_vertex;
        std::cin >> first_vertex >> second_vertex;
        graph[first_vertex - 1].add_neighbour(second_vertex - 1);
        graph[second_vertex - 1].add_neighbour(first_vertex - 1);
    }
    if (start_vertex == finish_vertex){
        std::cout<<0<<'\n'<<start_vertex;
        return 0;
    }
    if (!BFS(start_vertex - 1, finish_vertex - 1, graph)) {
        std::cout << -1;
    } else {
        std::vector<int> way;
        int current_vertex = finish_vertex - 1;
        way.emplace_back(finish_vertex - 1);
        while (graph[current_vertex].get_prev() != graph[current_vertex].get_num()) {
            way.emplace_back(graph[current_vertex].get_prev());
            current_vertex = graph[current_vertex].get_prev();
        }
        std::cout<<way.size() - 1<<'\n';
        for (int i = way.size() - 1; i >= 0; --i) {
            std::cout << way[i] + 1 << ' ';
        }
    }

}
