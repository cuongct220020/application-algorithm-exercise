// https://oj.vnoi.info/problem/geo_r
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

bool checkSide(Line &L, Point &A, Point &B) {
    int f1 = L.a * A.x + L.b * A.y + L.c;
    int f2 = L.a * B.x + L.b * B.y + L.c;
    return ((f1 * f2 > 0) ? true : false);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x0, y0, x1, y1, a, b, c;
    cin >> x0 >> y0 >> x1 >> y1 >> a >> b >> c;

    Point A(x0, y0), B(x1, y1);
    Line L(a, b, c);

    bool sameSide = checkSide(L, A, B);
    if (sameSide) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}