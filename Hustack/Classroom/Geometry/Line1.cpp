// https://oj.vnoi.info/problem/geo_l
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
};

struct Line {
    int a, b, c;
};

void makeLine(Point &A, Point &B, Line &L) {
    L.a = A.y - B.y;
    L.b = B.x - A.x;
    L.c = A.x * B.y - A.y * B.x;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point p1(x1, y1), p2(x2, y2);
    Line L;

    makeLine(p2, p1, L);

    cout << L.a << " " << L.b << " " << L.c << "\n";
    return 0;
}
