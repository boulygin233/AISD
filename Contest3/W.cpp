#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void Floyd(vector<vector<int>> &vertexes, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vertexes[i][j] > vertexes[i][k] + vertexes[k][j]) {
                    vertexes[i][j] = vertexes[i][k] + vertexes[k][j];
                }
            }
        }
    }
}

int main() {
    int n, start, finish;
    cin >> n >> start >> finish;
    vector<vector<int>> vertexes(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            cin>>vertexes[i][j];
            if (vertexes[i][j] == -1) {
                vertexes[i][j] = 500000000;
            }
        }
    }
    Floyd(vertexes, n);
    if (vertexes[start - 1][finish - 1] == 500000000){
        cout<<-1;
    }
    else{
        cout<<vertexes[start - 1][finish - 1];
    }
}
