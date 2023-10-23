#include <iostream>
#include <time.h>
using namespace std;

unsigned long modExpo (unsigned long a, unsigned long x, unsigned long n) {
    unsigned long res = 1;
    while (x > 0) {
        if (x%2 == 1)
            res = (res*a)%n;
        x = x/2;
        a = (a*a)%n;
    }
    return res;
}

int main () {
    srand(time(0));
    
    // checking for probability of liars in composite
    // if done for prime than prob would be 1;

    std::cout << "input a number.\n";
    unsigned long n;

    std::cin >> n;

    unsigned long count = 0;
    for (unsigned long a = 2; a <= n-2; a++) {
        if (modExpo(a,n-1,n) == 1)
            count++;
    }

    double prob = ((double)count)/(n-3);
    std::cout << " -- probability of liars is : " << prob;
    std::cout << "\n -- number of liars : " << count << std::endl;
    return 0;
}