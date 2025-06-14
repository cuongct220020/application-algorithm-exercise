// https://oj.vnoi.info/problem/geo_j
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Point {
    double x, y;
    //Point(int x, int y) : x(x), y(y) {};
};

struct Line {
    int a, b, c;
    Line(int a, int b, int c) : a(a), b(b), c(c) {};
};

void intersection(Point &O, Line &L1, Line &L2) {
    int denomirator = L1.a * L2.b - L2.a * L1.b;
    double x = 1.0 * (L2.c * L1.b - L1.c * L2.b) / denomirator;
    double y = 1.0 * (L1.c * L2.a - L2.c * L1.a) / denomirator;
    O.x = x;
    O.y = y;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    Line L1(a1, b1, c1), L2(a2, b2, c2);

    Point O;
    intersection(O, L1, L2);
    
    cout << fixed << setprecision(6) << O.x << " " << fixed << setprecision(6) << O.y << "\n";

    return 0;
}