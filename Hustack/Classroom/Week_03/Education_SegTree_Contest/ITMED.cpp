// https://oj.vnoi.info/problem/segtree_itmed
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 1;
const int INF = 1e18;

int n, k;
int a[N], st[4 * N], dp[N];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = -INF;
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = dp[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r && pos == l) {
        st[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(2 * id, l, m, pos, val);
    update(2 * id + 1, m + 1, r, pos, val);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int x, int y) {
    if (y < l || x > r) return -INF;
    if (x <= l && r <= y) return st[id];
    int m = (l + r) / 2;
    int left = get(2 * id, l, m, x, y);
    int right = get(2 * id + 1, m + 1, r, x, y);
    return max(left, right);
}

void solve() {
    for (int i = 1; i <= n; i++) {
        int left_seg = max(1ll, i - k);
        int right_seg = i - 1;
        int max_prev = get(1, 1, n, left_seg, right_seg);
        dp[i] = (max_prev > 0) ? max_prev + a[i] : a[i];
        update(1, 1, n, i, dp[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    build(1, 1, n);
    solve();

    return 0;
}