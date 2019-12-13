#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void addEdge(vector<int> *edgeTo, int edge){
    edgeTo->push_back(edge);
}

void Vertex(vector<int> *edge){
    for (int i = 0; i < edge->size(); ++i){
        cout<<(*edge)[i]<<' ';
    }
    cout<<'\n';
}

int main() {
    int edgesAmount;
    cin>>edgesAmount;
    int operationsAmount;
    cin>>operationsAmount;
    vector<vector<int>> edges(edgesAmount);
    for (int i = 0; i < operationsAmount; ++i){
        int operation;
        cin>>operation;
        if (operation == 1) {
            int edgeTo;
            int edgeAppend;
            cin>>edgeTo>>edgeAppend;
            addEdge(&(edges[edgeTo - 1]), edgeAppend);
            addEdge(&(edges[edgeAppend - 1]), edgeTo);
        }
        else {
            int edge;
            cin>>edge;
            Vertex(&(edges[edge - 1]));
        }
    }
}
