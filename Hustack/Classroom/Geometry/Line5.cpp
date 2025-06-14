// https://oj.vnoi.info/problem/geo_m
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

void makeLine(Line &L, Point &A, int u, int v) {
    L.a = u;
    L.b = v;
    L.c = - (u * A.x + v * A.y);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int xA, yA, u, v;
    cin >> xA >> yA >> u >> v;

    Point A(xA, yA);
    Line L;
    
    makeLine(L, A, u, v);
    
    cout << L.a << " " << L.b << " " << L.c << "\n";

    return 0;
}