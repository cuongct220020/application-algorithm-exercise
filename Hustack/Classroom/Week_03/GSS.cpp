// https://oj.vnoi.info/problem/gss
#include <bits/stdc++.h>
using namespace std;

#define N 50001
const int INF = 1e9 + 7; 

typedef struct _Node {
    int sum; // trong so cua doan [l, r]
    int best; // trong so cua day con lon nhat
    int prefix; // trong so lon nhat cua day con bat dau tu l
    int suffix; // trong so lon nhat cua day con ket thu tai r
} Node;

int n, m, a[N];
Node ST[4 * N];

Node combine(Node &left, Node &right) {
    Node res;

    res.sum = left.sum + right.sum;
    res.prefix = max(left.prefix, left.sum + right.prefix);
    res.suffix = max(right.suffix, right.sum + left.suffix);
    res.best = max(max(left.best, right.best), left.suffix + right.prefix);

    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    
    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);

    ST[id] = combine(ST[2 * id], ST[2 * id + 1]);
}

Node get(int id, int l, int r, int x, int y) {
    if (y < l || x > r) return {0, -INF, -INF, -INF};

    if (x <= l && r <= y) return ST[id];

    int m = (l + r) / 2;
    Node left = get(2 * id, l, m, x, y);
    Node right = get(2 * id + 1, m + 1, r, x, y);
    return combine(left, right);
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << get(1, 1, n, x, y).best << "\n";
    }
    return 0;
}