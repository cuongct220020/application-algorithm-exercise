// https://oj.vnoi.info/problem/geo_f
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

double dist(Line &L, Point &A) {
    int numerator = abs(L.a*A.x + L.b*A.y + L.c);
    double denomirator = sqrt(L.a*L.a + L.b*L.b);
    return (double) numerator/denomirator;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA>> xB >> yB >> xC >> yC;

    Point A(xA, yA), B(xB, yB), C(xC, yC);
    Line L;
    makeLine(B, C, L);

    cout << fixed << setprecision(6) << dist(L, A) << "\n";
    return 0;
}