#include <bits/stdc++.h>
using namespace std;

typedef struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {};
} Point;

struct Line {
    double a, b, c;
};

double dist(const Point &A, const Point &B) {
    double x = B.x - A.x;
    double y = B.y - A.y;
    return sqrt(x * x + y * y);
}
// Vector don vi
Point unitVector(const Point &A, const Point B) {
    Point unit;
    unit.x = (B.x - A.x) / dist(A, B);
    unit.y = (B.y - A.y) / dist(A, B);
    return unit;
}
// Vector chi phuong
Point directionVector(const Point &X, const Point &Y, const Point &Z) {
    Point direct;
    Point unit_XY = unitVector(X, Y);
    Point unit_XZ = unitVector(X, Z);
    direct.x = unit_XY.x + unit_XZ.x;
    direct.y = unit_XY.y + unit_XZ.y;
    return direct;
}
// Vector phap tuyen
Point normalVector(const Point &X, const Point &Y, const Point &Z) {
    Point normal;
    Point direct = directionVector(X, Y, Z);
    normal.x = -direct.y;
    normal.y = direct.x;
    return normal;
}

void makeBisector(Line &L, const Point &X, const Point &Y, const Point &Z) {
    Point normal = normalVector(X, Y, Z);
    L.a = normal.x;
    L.b = normal.y;
    L.c = -(L.a * X.x + L.b * X.y);

    // Kiểm tra dấu của hệ số và điều chỉnh nếu cần thiết
    if (L.a < 0 || (L.a == 0 && L.b < 0)) {
        L.a = -L.a;
        L.b = -L.b;
        L.c = -L.c;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double xX, yX, xY, yY, xZ, yZ;
    cin >> xX >> yX;
    cin >> xY >> yY;
    cin >> xZ >> yZ;

    Point X(xX, yX), Y(xY, yY), Z(xZ, yZ);
    Line L;
    makeBisector(L, X, Y, Z);

    cout << fixed << setprecision(10) << L.a << " " << L.b << " " << L.c << "\n";

    return 0;
}