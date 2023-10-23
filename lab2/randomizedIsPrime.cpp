#include <iostream>
#include <time.h>
using namespace std;

unsigned long gcd (unsigned long a, unsigned long b) {
    while (b > 0) {
        unsigned long mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

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

bool isPrime (unsigned long n, int k) {

    // handling corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n == 2 || n == 3)
        return true;

    while (k-- > 0) {
        // randomly selecting 'a'

        // as 2 <= 'a' <= n-2
        unsigned long a = 2 + rand()%(n-3);

        if (gcd(a,n) != 1)
            return false;

        if (modExpo(a,n-1,n) != 1)
            return false;

    }
    return true;
}

int main () {
    srand(time(0));
    int k = 100000000;
    std::cout << "input a number for primality testing.\n";
    unsigned long n;

    std::cin >> n;

    if (isPrime(n,k) == true)
        std::cout << " -- " << n << " is prime. -- " << std::endl;
    else
        std::cout << " -- " << n << " is composite. -- " << std::endl;

    return 0;
}