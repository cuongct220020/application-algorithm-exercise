// https://oj.vnoi.info/problem/geo_k
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    double x, y;
    Point(int x, int y) : x(x), y(y) {};
};

double dist(Point &a, Point &b) {
    ll x = a.x - b.x;
    ll y = a.y - b.y;
    return sqrt(1ll * x*x + 1ll * y*y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point p1(x1, y1), p2(x2, y2);

    cout << fixed << setprecision(6) << dist(p1, p2) << "\n";

    return 0;
}