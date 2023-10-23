#include <bits\stdc++.h>
using namespace std;

class Point {
public :
    int x;
    int y;

    Point (int x, int y) : x(x), y(y) {}
};

int main () {
    const int N = 10;
    vector<Point> points = {
        Point(10, 20), Point(90, -12), Point(0, 0), Point(8, -78), Point(-2, 9),
        Point(9, 0), Point(34, -9), Point(-48, 81), Point(-1, 90), Point(25, -100)};

    int d_min = INT_MAX, d;
    int ans_point1 = 0, ans_point2 = 0;

    for (int i = 0; i < N -1; i++) {
        for (int j = i + 1; j < N; j++) {
            int x1 = points[i].x;
            int x2 = points[j].x;
            int y1 = points[i].y;
            int y2 = points[j].y;

            d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

            if (d < d_min) {
                d_min = d;

                ans_point1 = i;
                ans_point2 = j;
            }
        }
    }

    cout << " -- Minimum distance is : " << d << std::endl;
    cout << " -- Between Point " << ans_point1 << " and Point " << ans_point2 << std::endl;
    return 0;
}