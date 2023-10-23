#include <bits\stdc++.h>
using namespace std;

void compute_lps (vector<int> &lps, const int &M, string &pattern) {
    int k = -1;
    for (int q = 1; q < M; q++) {
        while (k > -1 && pattern[k + 1] != pattern[q])
            k = lps[k];
        if (pattern[k + 1] == pattern[q])
            k++;

        lps[q] = k;
    }
}

int main () {
    string text = "acacacacac";
    string pattern = "acac";

    const int N = text.length();
    const int M = pattern.length();

    vector<int> lps(M, 0);
    compute_lps(lps, M, pattern);

    int q = -1;
    for (int i = 0; i < N; i++) {
        while (q > -1 && pattern[q + 1] != text[i])
            q = lps[q];

        if (pattern[q + 1] == text[i])
            q++;

        if (q == M -1) {
            std::cout << " \n--PATTERN found at index : " << i - M + 1 << std::endl;
            q = lps[q];
        }
    }

    return 0;
}