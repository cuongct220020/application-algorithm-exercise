#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;

struct Point {
  int x, y;
  Point() : x(0), y(0) {};
  Point(int x, int y) : x(x), y(y) {};
};

int n, m;
Point P[N];
vector<Point> C;

int dist2(const Point &O, const Point &A) {
    int x = A.x - O.x;
    int y = A.y - O.y;
    return x * x + y * y;
}

int cross_product(const Point &O, const Point &A, const Point &B) {
    int xA = A.x - O.x; int yA = A.y - O.y;
    int xB = B.x - O.x; int yB = B.y - O.y;
    return xA * yB - yA * xB;
}

bool cmp(Point &A, Point &B) {
    int cp = cross_product(P[0], A, B);
    return (cp == 0) ? dist2(P[0], A) < dist2(P[0], B) : cp > 0;
}

int ccw(const Point &O, const Point &A, const Point &B) {
    int cp = cross_product(O, A, B);
    return (cp == 0) ? 0 : (cp > 0 ? 1 : -1);
}

void buildConvexHull(Point *P) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (P[i].y < P[k].y || (P[i].y == P[k].y && P[i].x < P[k].x)) {
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
}

bool same_side(const Point &A, const Point &B, const Point &C, const Point &D) {
    int cp1 = ccw(A, B, C);
    int cp2 = ccw(A, B, D);
    return (cp1 * cp2 >= 0);
}

bool checkOnConvexHull(vector<Point> &C, const Point &T) {
    int last = C.size() - 1;
    if (!same_side(C[0], C[1], C[last], T) || 
        !same_side(C[0], C[last], C[1], T)) {
            return false;
        }
        
    int left = 1, right = last;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (same_side(C[0], T, C[1], C[mid])) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    if (!same_side(C[left], C[right], C[0], T)) {
        return false;
    }
    
    return true;
}


signed main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    
    buildConvexHull(P);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Point T(x, y);
        bool onConvexHull = checkOnConvexHull(C, T);
        
        cout << ((onConvexHull == true) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}