#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 1;

struct Point {
    int x, y;
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {};
};

int n;
Point P[N];
vector<Point> C;

int dist2(Point &O, Point &A) {
    int x = A.x - O.x;
    int y = A.y - O.y;
    return x*x + y*y;
}

int cross_product(Point &O, Point &A, Point &B) {
    int xA = A.x - O.x;
    int yA = A.y - O.y;
    int xB = B.x - O.x;
    int yB = B.y - O.y;
    return xA*yB - yA*xB;
}

bool cmp(Point &A, Point &B) {
    int cp = cross_product(P[0], A, B);
    return (cp == 0) ? dist2(P[0], A) < dist2(P[0], B) : cp > 0;
}

int ccw(Point &O, Point &A, Point &B) {
    int cp = cross_product(O, A, B);
    return (cp ==  0) ? 0 : (cp > 0 ? 1 : -1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    
    int k = 0;
    
    // find bottom-left point
    for (int i = 0; i < n; i++) {
        if (P[i]. y < P[k].y || (P[i].y == P[k].y && P[i].x < P[k].x)) {
            k = i;
        }
    }
    swap(P[0], P[k]);
    sort(P + 1, P + n, cmp);
    C.push_back(P[0]);
    C.push_back(P[1]);
    
    for (int i = 2; i < n; i++) {
        while (C.size() > 1 && ccw(C[C.size() - 2], C[C.size() - 1], P[i]) <= 0) {
            C.pop_back();
        }
        C.push_back(P[i]);
    }
    
    int sizeC = C.size();
    cout << sizeC << "\n";
    for (int i = 0; i < sizeC; i++) {
        cout << C[i].x << " " << C[i].y << "\n";
    }

    return 0;
}