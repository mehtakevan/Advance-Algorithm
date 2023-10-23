// A C++ program to find convex hull of a set of points.
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

// reference to the first point Used in compare function of qsort() 
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
bool comparePoints(Point p1, Point p2)
{
    // return 0, 1, -1
    double theta1 = 0, theta2 = 0;
    theta1 = atan((p1.y - p0.y) / (p1.x - p0.x))*(180/3.1415);
    theta2 = atan((p2.y - p0.y) / (p2.x - p0.x))*(180/3.1415);

    return (theta1 < theta2);
}

int direction (Point xp, Point yp, Point zp) {
    // z - x * y - x
    Point z_x, y_x;

    z_x.y = zp.y - xp.y;
    z_x.x = zp.x - xp.x;

    y_x.y = yp.y - xp.y;
    y_x.x = yp.x - xp.x;

    return ((z_x.x * y_x.y) - (z_x.y * y_x.x));
}

// Prints convex hull of a set of n points.
void convexHull(vector<Point> &points)
{
    // length of given points
    const int N = points.size(); 

    // Find the bottommost point
    int ymin = points[0].y, min = 0;

    for (int i = 1; i < N; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or choose the left in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    // swap point at min index with 0th index
    Point temp = points[min];
    points[min] = points[0];
    points[0] = temp;


    // Sort n-1 points with respect to the first point according to polar angles
    p0 = points[0];
    sort(points.begin() + 1, points.end(), comparePoints);

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < N; i++)
    {
        while (direction(nextToTop(S), S.top(), points[i]) >= 0)
            S.pop();

        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    while (!S.empty())
    {
        Point p = S.top();
        std::cout << "Point : (" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}

int main()
{
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    convexHull(points);
    return 0;
}