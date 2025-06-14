#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
const ll INF = 1e18;

typedef struct Node {
    ll lazy;
    ll max_val;
} Node;

int n, q, a[N];
Node ST[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id].max_val = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    
    ST[id].max_val = max(ST[2 * id].max_val, ST[2 * id + 1].max_val);
}

void push(int id) {
    ll tmp = ST[id].lazy;

    ST[2 * id].lazy += tmp;
    ST[2 * id].max_val += tmp;

    ST[2 * id + 1].lazy += tmp;
    ST[2 * id + 1].max_val += tmp;

    ST[id].lazy = 0;
}

void update(int id, int l, int r, int x, int y, ll val) {
    if (y < l || r < x) return;

    if (x <= l && r <= y) {
        ST[id].lazy += val;
        ST[id].max_val += val;
        return;
    }
    push(id);

    int m = (l + r) / 2;
    update(2 * id, l, m, x, y, val);
    update(2 * id + 1, m + 1, r, x, y, val);

    ST[id].max_val = max(ST[2 * id].max_val, ST[2 * id + 1].max_val);
}

ll get(int id, int l, int r, int x, int y) {
    if (y < l || r < x) return -INF;

    if (x <= l && r <= y) {
        return ST[id].max_val;
    }
    push(id);

    int m = (l + r) / 2;
    ll maxLeft = get(2 * id, l, m, x, y);
    ll maxRight = get(2 * id + 1, m + 1, r, x, y);

    return max(maxLeft, maxRight);
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);

    cin >> q;
    while (q--) {
        string tok;
        cin >> tok;

        if (tok == "1") {
            int x, y;
            ll val;
            cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }

        if (tok == "2") {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}