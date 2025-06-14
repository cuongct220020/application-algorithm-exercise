// https://oj.vnoi.info/problem/geo_e
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
};

struct Line {
    int a, b, c;
    Line(int a, int b, int c) : a(a), b(b), c(c) {};
};

double dist(Line &L, Point &A) {
    int numerator = abs(L.a*A.x + L.b*A.y + L.c);
    double denomirator = sqrt(L.a*L.a + L.b*L.b);
    return (double) numerator/denomirator;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    Point A(x, y);
    Line L(a, b, c);

    cout << fixed << setprecision(8) << dist(L, A) << "\n";
    return 0;
}