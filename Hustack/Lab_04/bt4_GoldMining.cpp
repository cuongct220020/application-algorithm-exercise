#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MN = 1e6 + 1;
const int INF = 1e9;
int a[MN], st[4 * MN], dp[MN];

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
    if (l == r && pos == r) {
        st[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(2 * id, l, m, pos, val);
    update(2 * id + 1, m + 1, r, pos, val);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int x, int y) {
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return st[id];

    int m = (l + r) / 2;
    int left = get(2 * id, l, m, x, y);
    int right = get(2 * id + 1, m + 1, r, x, y);
    return max(left, right);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l1, l2;
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 0;

    }
    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        if (i <= l1) {
            dp[i] = a[i];
            update(1, 1, n, i, dp[i]);
            continue;
        }
        int left_seg = max(1ll, i - l2);
        int right_seg = i - l1;
        dp[i] = a[i] + get(1, 1, n, left_seg, right_seg);
        update(1, 1, n, i, dp[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}