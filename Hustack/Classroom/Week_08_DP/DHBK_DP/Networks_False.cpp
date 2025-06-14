// https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/B

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
const int N = 10001;
const int M = 10001;
const int K = 2001;

int n, m, k;
int g[N][N], dp[K][N];

void input() {
    cin >> n >> k;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
    }
}

void solve() {
    // khoi tao
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 0;
    }

    // quy hoach dong
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int u = 1; u <= n; u++) {
                if (g[u][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][u] + g[u][j]);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[k][i]);
    }

    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}