#include <bits\stdc++.h>
using namespace std;

int main () {
    string text = "ACTGACTACAGACACAGACACAGATCGACAA";
    string pattern = "ACACAGA";

    const int M = pattern.length(); // length of pattern
    const int N = text.length();
    const int E = 4; // length of set of alphabets

    // finite automaton table
    unordered_map<char, int> char_map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    // table :- rows : 0 to M, cols : 0 to E -1
    vector<vector<int>> table = {
       //A  C  G  T
        {1, 0, 0, 0},
        {1, 2, 0, 0},
        {3, 0, 0, 0},
        {1, 4, 0 ,0},
        {5, 0, 0, 0},
        {1, 4, 6, 0},
        {7, 0, 0, 0},
        {1, 2, 0 ,0}};


    // initial state
    int q = 0;

    // string matching part
    for (int i = 0; i < N; i++) {
        int index = char_map[text[i]];
        q = table[q][index];
        if (q == M) {
            cout << " \n-- PATTERN found at index : " << i - M + 1 << std::endl;
        }
    }
    return 0;
}