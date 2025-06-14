// https://oj.vnoi.info/problem/segtree_itds1
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
const int INF = 1e18;

int n, m;
int a[N];
multiset<int> st[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].insert(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id].insert(st[2 * id].begin(), st[2 * id].end());
    st[id].insert(st[2 * id + 1].begin(), st[2 * id + 1].end());
}

int query(int id, int l, int r, int L, int R, int k) {
    if (r < L || l > R) return INF;
    if (L <= l && r <= R) {
        auto it = st[id].lower_bound(k);
        return (it != st[id].end()) ? *it : INF;
    }
    int mid = (l + r) / 2;
    return min(query(2 * id, l, mid, L, R, k),
               query(2 * id + 1, mid + 1, r, L, R, k));
}

void update(int id, int l, int r, int pos, int old_val, int new_val) {
    st[id].erase(st[id].lower_bound(old_val));
    st[id].insert(new_val);
    if (l == r) return;
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * id, l, mid, pos, old_val, new_val);
    else update(2 * id + 1, mid + 1, r, pos, old_val, new_val);
}

signed main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, a[i], v);
            a[i] = v;
        } else if (type == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            int res = query(1, 1, n, l, r, k);
            cout << (res == INF ? -1 : res) << "\n";
        }
    }

    return 0;
}
