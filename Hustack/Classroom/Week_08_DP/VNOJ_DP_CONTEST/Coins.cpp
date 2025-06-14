// https://oj.vnoi.info/problem/atcoder_dp_i
#include <bits/stdc++.h>
using namespace std;
const int N = 3000;

int n;
long double p[N], dp[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // dp[i][j] xac xuat de j dong xu la mat ngua neu da tung duoc i dong xu

    dp[1][1] = p[1]; dp[1][0] = 1 - p[1];

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] * double(1 - p[i]);
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            }
        }
    }

    int k = n / 2 + 1;
    double ans = 0;
    for (int i = n; i >= k; i--) ans += dp[n][i];

    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}