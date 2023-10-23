#include <iostream>
#include <string>
using namespace std;

int main () {
    string text = "hello world llo";
    string pattern = "llo";
    int N = text.length(), M = pattern.length();
    int comparisons = 0, shifts = 0;
    
    for (int i = 0; i <= N - M; i++) {
        int j;
        shifts++;
        for (j = 0; j < M; j++) { 
            comparisons++;
            if (pattern[j] != text[j + i]) { 
                break;
            }
        }
        if (j == M) {
            std::cout << "\n-- match at index : " << i << std::endl;
        }
    }
    std::cout << "\nTotal comparisons : " << comparisons << std::endl;
    std::cout << "\nTotal shifts : " << shifts << std::endl;
    return 0;
}