#include <iostream>
#include <string>
using namespace std;

int main () {
    string text = "hello world llo";
    string pattern = "llo";
    int N = text.length(), M = pattern.length();
    int comparisons = 0, shifts = 0;

    // ------------- preprocessing -------------
    int shift[128]; // shift table for 128 ascii characters
    for (int i = 0; i < 128; i++) {
        shift[i] = M;  // initializing values to 'M'
    }

    // filling up shift table for 'pattern' upto 'M -1' characters
    for (int i = 0; i < M - 1; i++) {
        shift[pattern[i] - ' '] = M - 1 - i;
    }

    // ------------- matching -------------
    int j = 0;
    while (j + M <= N) {
        comparisons++;
        shifts++;
        if (text[j + M - 1] == pattern[M - 1]) {
            int i = M - 2;
            while (i >= 0 && text[j + i] == pattern[i]) {
                i--;
                comparisons++;
            }

            if (i == -1) {
                std::cout << "\n-- match at index : " << j << std::endl;
            }
        }
        // if matches or not
        // we will need to shift by the last element of window in 'text'
        j += shift[text[j + M - 1] - ' '];
    }
    
    std::cout << "\nTotal comparisons : " << comparisons << std::endl;
    std::cout << "\nTotal shifts : " << shifts << std::endl;
    return 0;
}