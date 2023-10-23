#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

int iterations = 0;

using namespace std;

bool bfs (vector<vector<int>> rGraph, int s, int t, vector<int> &parent) {
    int N = rGraph.size();
    vector<int> visited (N, 0);
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < N; v++) {
            if (visited[v] == 0 && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return false;
}

int fordFulkerson (int N, vector<vector<int>> graph, int s, int t) {
    // creating residual graph
    vector<vector<int>> rGraph (N, vector<int>(N, 0));
    for (int  i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rGraph[i][j] = graph[i][j];
        }
    }
    
    int max_flow = 0;
    vector<int> parent(N,-1);
    
    while (bfs(rGraph, s, t, parent)) {
        
        iterations++;
        
        int bottleneck = INT_MAX;
        
        // figuring out bottleneck capacity
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, rGraph[u][v]);
        }
        
        // updating forward edge with remaining flow
        // and reverse edge with flow sent till now
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= bottleneck;
            rGraph[v][u] += bottleneck;
        }
        
        max_flow += bottleneck;
    }
    
    return max_flow;
}

int main () {
    // int N = 6; // 6 vertices
    // vector<vector<int>> graph = { 
    //     {0, 16, 13, 0, 0 ,0},
    //     {0, 0, 10, 12, 0, 0},
    //     {0, 4, 0, 0, 14, 0},
    //     {0, 0, 9, 0, 0, 20},
    //     {0, 0, 0, 7, 0, 4},
    //     {0, 0, 0, 0, 0, 0}
    // };
    
    int N = 4; // 4 vertices
    vector<vector<int>> graph = { 
        {0, 1000000, 1000000, 0},
        {0, 0, 1, 1000000},
        {0, 0, 0, 1000000},
        {0, 0, 0, 0}
    };

    std::cout << "max flow : " << fordFulkerson(N, graph, 0, N-1);
    std::cout << "\niterations : " << iterations;
    return 0;
}