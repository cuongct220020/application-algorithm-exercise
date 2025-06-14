// https://oj.vnoi.info/problem/geo_o
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
};

struct Line {
    int A, B, C;
    Line(int A, int B, int C) : A(A), B(B), C(C) {};
};

bool checkPointOnLine(Line &L, Point &P) {
    int check = L.A * P.x + L.B * P.y + L.C;
    return ((check == 0) ? true : false);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, A, B, C;
    cin >> x >> y >> A >> B >> C;
    
    Point P(x, y);
    Line L(A, B, C);

    bool isPointOnLine = checkPointOnLine(L, P);
    if (isPointOnLine) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}