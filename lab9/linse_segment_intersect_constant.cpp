#include <bits/stdc++.h>
using namespace std;


int direction (pair<int, int> &x, pair<int, int> &y, pair<int, int> &z) {
    int d = 0;
    // z - x * y -x
    pair<int, int> z_x, y_x;
   
    z_x.second = z.second - x.second;
    z_x.first = z.first - x.first;
   
    y_x.second = y.second - x.second;
    y_x.first = y.first - x.first;
   
    d = (z_x.first * y_x.second) - (z_x.second * y_x.first);
    return d;
}


bool onSegment (pair<int, int> &x, pair<int, int> &y, pair<int, int> &z) {
    if ( min(x.first, y.first) <= z.first && max(x.first, y.first) >= z.first ) {
        if ( min(x.second, y.second) <= z.second && max(x.second, y.second) >= z.second )
            return true;
        else
            return false;
    }
    else
        return false;
}


int main () {
    vector<pair<int, int>> ls1 = {{1,2}, {5,10}};
    vector<pair<int, int>> ls2 = {{1,10}, {5,2}};
   
    int d1 = direction(ls1[0], ls1[1], ls2[0]);
    int d2 = direction(ls1[0], ls1[1], ls2[1]);
    int d3 = direction(ls2[0], ls2[1], ls1[0]);
    int d4 = direction(ls2[0], ls2[1], ls1[1]);
   
    if (d1 * d2 < 0 && d3 * d4 < 0)
        std::cout << "\nINTERSECTING !!!\n";
    else if (d1 == 0 && onSegment(ls1[0], ls1[1], ls2[0]))
        std::cout << "\nINTERSECTING !!!\n";
    else if (d2 == 0 && onSegment(ls1[0], ls1[1], ls2[1]))
        std::cout << "\nINTERSECTING !!!\n";
    else if (d3 == 0 && onSegment(ls2[0], ls2[1], ls1[0]))
        std::cout << "\nINTERSECTING !!!\n";
    else if (d4 == 0 && onSegment(ls2[0], ls2[1], ls1[1]))
        std::cout << "\nINTERSECTING !!!\n";
    else
        std::cout << "\nNOT INTERSECTING !!!\n";
}