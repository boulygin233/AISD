#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using std::vector;
using std::set;
using std::map;
using std::cin;
using std::cout;

struct Edge {
    int from;
    int to;

    Edge(int from, int to): from(std::min(from, to)), to(std::max(from, to)) {}

    bool operator<(const Edge &other) const {
        return (from < other.from) || (from == other.from && to < other.to);
    }
};

class Graph {
protected:
    int vertex_count;
    int edge_count;
    bool is_directed;

public:
    typedef int Vertex;

    Graph(int vertex_count, bool is_directed) : vertex_count(vertex_count), is_directed(is_directed), edge_count(0) {}

    int GetVertexCount()  {
        return vertex_count;
    }

    virtual void add_edge( Vertex &start,  Vertex &finish) = 0;

    virtual vector<Vertex> get_neighbors( Vertex &vertex)  = 0;
};

class GraphAdjList : public Graph {
private:

    vector<vector<Vertex>> adj_list;

public:
    GraphAdjList(int vertex_count, bool is_directed) : Graph(vertex_count, is_directed), adj_list(vertex_count + 1) {}

    void add_edge( Vertex &start,  Vertex &finish) override {
        adj_list[start].push_back(finish);
        if (!is_directed) {
            adj_list[finish].push_back(start);
        }
        ++edge_count;
    }

    vector<Vertex> get_neighbors( Vertex &vertex)  override {
        return adj_list[vertex];
    }

};


struct BridgesInfo {
    vector<bool> visited;
    vector<int> time_in;
    vector<int> time_up;
    int time;
    set<Edge> bridges;

    explicit BridgesInfo(int vertex_count)
            : visited(vertex_count + 1, false),
              time_in(vertex_count + 1, 0),
              time_up(vertex_count + 1, 0),
              time(0) {}
};

void DFS(Graph &graph, int &vertex, BridgesInfo &bridges_info, int &predecessor) {
    bridges_info.time_in[vertex] = bridges_info.time_up[vertex] = ++bridges_info.time;
    bridges_info.visited[vertex] = true;
    for (int u : graph.get_neighbors(vertex)) {
        if (u == predecessor) {
            continue;
        }
        if (bridges_info.visited[u]) {
            bridges_info.time_up[vertex] = std::min(bridges_info.time_up[vertex],
                                                    bridges_info.time_in[u]);
        } else {
            DFS(graph, u, bridges_info, vertex);
            bridges_info.time_up[vertex] = std::min(bridges_info.time_up[vertex],
                                                    bridges_info.time_up[u]);
            if (bridges_info.time_up[u] > bridges_info.time_in[vertex]) {
                bridges_info.bridges.insert(Edge(vertex, u));
            }
        }
    }
}

set<Edge> GetBridges(Graph &graph) {
     int vertex_count = graph.GetVertexCount();
    BridgesInfo bridges_info = BridgesInfo(vertex_count);
    for (int vertex = 1; vertex < vertex_count + 1; ++vertex) {
        if (!bridges_info.visited[vertex]) {
            DFS(graph, vertex, bridges_info, vertex);
        }
    }
    return bridges_info.bridges;
}


int main() {
    int n, m;
    cin >> n >> m;
    GraphAdjList graph_adj_list = GraphAdjList(n, false);
    map<Edge, int> edge_index;

    for (int i = 1; i < m + 1; ++i) {
        int first_vertex, second_vertex;
        cin >> first_vertex >> second_vertex;
        graph_adj_list.add_edge(first_vertex, second_vertex);
        if (edge_index.find(Edge(first_vertex, second_vertex)) == edge_index.end()) {
            edge_index[Edge(first_vertex, second_vertex)] = i;
        } else {
            edge_index[Edge(first_vertex, second_vertex)] = -1;
        }
    }

    set<int> edge_id;
    for (auto bridge : GetBridges(graph_adj_list)) {
        if (edge_index[bridge] != -1) {
            edge_id.insert(edge_index[bridge]);
        }
    }
    cout << edge_id.size() << '\n';
    for (auto id : edge_id) {
        cout << id << ' ';
    }
}
