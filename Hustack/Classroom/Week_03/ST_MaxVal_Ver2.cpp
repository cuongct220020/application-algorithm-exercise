// https://oj.vnoi.info/problem/qmax2
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 50000;

typedef struct _Node {
    int lazy;
    int val;
} Node;

int a[N];
Node ST[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id].val = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    
    ST[id].val = max(ST[id * 2].val, ST[id * 2 + 1].val);
}

void down(int id) {
    int t = ST[id].lazy;

    ST[id * 2].lazy += t;
    ST[id * 2].val += t;

    ST[id * 2 + 1].lazy += t;
    ST[id * 2 + 1].val += t;

    ST[id].lazy = 0;
} 

void update(int id, int l, int r, int x, int y, int k) {
    if (y < l || r < x) return;

    if (x <= l && r <= y) {
        ST[id].lazy += k;
        ST[id].val += k;
        return;
    }
    down(id);

    int m = (l + r) / 2;
    update(id * 2, l, m, x, y, k);
    update(id * 2 + 1, m + 1, r, x, y, k);

    ST[id].val = max(ST[id * 2].val, ST[id * 2 + 1].val);
}

int get(int id, int l, int r, int x, int y) {
    if (y < l || r < x) return -INF;

    if (x <= l && r <= y) {
        return ST[id].val;
    }
    down(id);

    int m = (l + r) / 2;
    int maxLeft = get(id * 2, l, m, x, y);
    int maxRight = get(id * 2 + 1, m + 1, r, x, y);

    return max(maxLeft, maxRight);
}

int main() {
    memset(a, 0, sizeof(a));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    build(1, 1, n);

    while (m--) {
        string tok;
        cin >> tok;
        if (tok == "0") {
            int x, y, k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }

        if (tok == "1") {
            int x, y;
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}