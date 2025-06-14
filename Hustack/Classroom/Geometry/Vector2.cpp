// https://oj.vnoi.info/problem/geo_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
};

double calcTheta(Point &A) {
    double theta = atan2(A.y, A.x);
    if (theta < 0) {
        theta += 2 * M_PI;
    }
    return theta;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y; 
    cin >> x >> y;

    Point A(x, y);

    cout << fixed << setprecision(10) << calcTheta(A) << "\n";
    return 0;
}