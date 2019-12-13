#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::set;
using std::cin;
using std::cout;

class Graph {
protected:
    int vertex_count;
    int edge_count;
    bool is_directed;

public:

    Graph(int vertex_count, bool is_directed) : vertex_count(vertex_count), is_directed(is_directed),
                                                edge_count(0) {}

    int GetVertexCount() {
        return vertex_count;
    }

    virtual void AddEdge(int &start, int &finish) = 0;

    virtual vector<int> GetAllNeighbors(int &vertex) = 0;

};

class GraphAdjList : public Graph {
private:
    vector<vector<int>> adj_list_;

public:
    GraphAdjList(int vertex_count, bool is_directed)
            : Graph(vertex_count, is_directed),
              adj_list_(vertex_count + 1) {}

    void AddEdge(int &start, int &finish) override {
        adj_list_[start].push_back(finish);
        if (!is_directed) {
            adj_list_[finish].push_back(start);
        }
        ++edge_count;
    }

    vector<int> GetAllNeighbors(int &vertex) override {
        return adj_list_[vertex];
    }
};


struct VerticesCondition {
    vector<bool> visited;
    vector<int> time_in;
    vector<int> time_up;
    int time;
    set<int> cut_vertices;

    explicit VerticesCondition(int vertex_count) : visited(vertex_count + 1, false), time_in(vertex_count + 1, 0),
                                                   time_up(vertex_count + 1, 0), time(0) {}
};

void DFS(Graph &graph, int &vertex, VerticesCondition &vertices_condition, int &predecessor) {
    bool is_root = (predecessor == vertex);
    vertices_condition.time_in[vertex] = vertices_condition.time_up[vertex] = ++vertices_condition.time;
    vertices_condition.visited[vertex] = true;
    int children = 0;
    for (int u : graph.GetAllNeighbors(vertex)) {
        if (u == predecessor) {
            continue;
        }
        if (vertices_condition.visited[u]) {
            vertices_condition.time_up[vertex] = std::min(vertices_condition.time_up[vertex],
                                                          vertices_condition.time_in[u]);
        } else {
            DFS(graph, u, vertices_condition, vertex);
            ++children;
            vertices_condition.time_up[vertex] = std::min(vertices_condition.time_up[vertex],
                                                          vertices_condition.time_up[u]);
            if (!is_root && vertices_condition.time_up[u] >= vertices_condition.time_in[vertex]) {
                vertices_condition.cut_vertices.insert(vertex);
            }
        }
    }
    if (is_root && children >= 2) {
        vertices_condition.cut_vertices.insert(vertex);
    }
}

set<int> GetCutVertices(Graph &graph) {
    int vertex_count = graph.GetVertexCount();
    VerticesCondition vertices_condition = VerticesCondition(vertex_count);
    for (int vertex = 1; vertex < vertex_count + 1; ++vertex) {
        if (!vertices_condition.visited[vertex]) {
            DFS(graph, vertex, vertices_condition, vertex);
        }
    }
    return vertices_condition.cut_vertices;
}


int main() {
    int n, m;

    cin >> n >> m;
    GraphAdjList graph_adj_list = GraphAdjList(n, false);

    for (int i = 0; i < m; ++i) {
        int start, finish;
        cin >> start >> finish;
        graph_adj_list.AddEdge(start, finish);
    }

    auto cut_vertices = GetCutVertices(graph_adj_list);
    cout << cut_vertices.size() << '\n';
    for (auto cut_vertex : cut_vertices) {
        cout << cut_vertex << '\n';
    }
}
