// https://oj.vnoi.info/problem/geo_b
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
};

int dotProduct(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y;
}

double dist(const Point &A) {
    return sqrt(A.x * A.x + A.y * A.y);
}

double calcAlpha(const Point &A, const Point &B) {
    return acos(dotProduct(A, B) / (dist(A) * dist(B)));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x0, y0, x1, y1; 
    cin >> x0 >> y0;
    cin >> x1 >> y1;

    Point A(x0, y0), B(x1, y1);

    cout << fixed << setprecision(10) << calcAlpha(A, B) << "\n";
    return 0;
}