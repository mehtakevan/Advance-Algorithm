#include <bits/stdc++.h>
using namespace std;

int main () {
    set<int> result;
    vector<pair<int, int>> edges = {{1,2}, {1,3}, {2,3}, {2,4}, {3,5}, {4,5}, {4,6}};
    int M = edges.size();
    
    srand(time(0));
    while (!edges.empty()) {
        int i = rand() % M;
        int u = edges[i].first, v = edges[i].second;
        result.insert(u);
        result.insert(v);
        
        // remove all the edges having u or v in edges
        for (int j = 0; j < M; j++) {
            int x = edges[j].first, y = edges[j].second;
            if ((x == u) || (y == v) || (x == v) || (y == u)) {
                pair<int, int> temp = edges[j];
                edges[j] = edges[M -1];
                edges[M -1] = temp;
                edges.pop_back();
                M--;
                j--;
            }
        }
    }
    
    // printing result
    for (auto v : result) {
        std::cout << "vertice : " << v << std::endl;
    }
    return 0;
}