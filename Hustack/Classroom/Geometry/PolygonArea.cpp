#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Point {
    ll x, y;
} Point;

double calcPolygonArea(vector<Point> &Ps, int n) {
    ll S = 0;

    for (int i = 1; i <= n; i++) {
        S += Ps[i].x * Ps[i % n + 1].y - Ps[i].y * Ps[i % n + 1].x;
    }
    return abs(S / 2.0);
}

int main() {
    //freopen("input.txt","r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<Point> Ps(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> Ps[i].x >> Ps[i].y;
    }

    cout << fixed << setprecision(6) << calcPolygonArea(Ps, n) << "\n";

    return 0;
}