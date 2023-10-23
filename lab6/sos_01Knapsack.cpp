#include <bits/stdc++.h>
using namespace std;

bool Knapsack_01(vector<int> &profit, vector<int> &weight, int &req_profit, int &capacity) {
    const int N = profit.size();

    vector<vector<int>> m(N + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j < weight[i]) {
                m[i][j] = m[i -1][j];
            }
            else {
                m[i][j] = max(profit[i] + m[i -1][j - weight[i]], m[i -1][j]);
            }
        }
    }

    if (m[N][capacity] >= req_profit)
        return true;

    return false;
}

void sum_of_subset(vector<int> &set, int &sum) {
    int req_profit = sum;
    int capacity = sum;
    
    // setting up profit and weight of items
    vector<int> profit = set;
    vector<int> weight = set;

    bool possible = Knapsack_01(profit, weight, req_profit, capacity);
    if (possible == true) { // if there exists a subset whose sum equals given sum
        std::cout << " -- sum POSSIBLE";
    }
    else {
        std::cout << " -- sum NOT POSSIBLE";
    }
}

int main () {
    vector<int> set = {4, 3, 6, 8, 5, 9};
    int sum = 23;
    sum_of_subset(set, sum);
    return 0;
}