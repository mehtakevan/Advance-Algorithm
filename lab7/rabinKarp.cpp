#include <bits/stdc++.h>
using namespace std;

int power (int a, int x) {
    int res = 1;
    while (x > 0) {
        if (x%2 == 1)
            res = (res*a);
        x = x/2;
        a = (a*a);
    }
    return res;
}

void rabin_karp(string &text, string &pattern, int &q, int d) {
    int n = text.length();
    int m = pattern.length();
    int h = power(d, m-1);
    
    int p = 0;
    int ts = 0;

    for (int i = 0; i < m; i++) {
        p = d*p + (pattern[i] - '0');
        ts = d*ts + (text[i] - '0');
    }

    p %= q;
    ts %= q;

    for (int s = 0; s <= n - m; s++) {
        if (p == ts) {
            int i;
            for (i = 0; i < m; i++) {
                if (pattern[i] != text[s + i])
                    break;
            }
            if (i == m) {
                std::cout << "\n  --pattern match at : " << s << std::endl;
            }
        }
        if (s < n - m) {
            ts = (ts - (text[s] - '0')*h)*d + (text[s + m] - '0');
            ts %= q;
            while (ts < 0) {
                ts += q;
            }
        }
    }
}

int main() {
    string text = "1234567890456";
    string pattern = "456";
    int q = 13;

    rabin_karp(text, pattern, q, 10.0);
    return 0;
}