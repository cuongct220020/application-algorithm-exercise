#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 1;

int n, m, a[N]; 

void preprocess(vector<vector<int>> &dp) {
    // khoi tao
    for (int j = 0; j < n; j++) {
        dp[0][j] = a[j];
    }
    
    // quy hoach dong
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int rmq(int l, int r, vector<vector<int>> &dp) {
    int k = log2(r - l + 1);
    int ans = min(dp[k][l], dp[k][r - (1 << k) + 1]);
    
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_log = log2(n) + 1;
    vector<vector<int>> dp(max_log, vector<int> (n));
    preprocess(dp);
    
    
    cin >> m;
    int ans = 0;
    while (m--) {
        int i, j;
        cin >> i >> j;
        ans += rmq(i, j, dp);
    }
    
    cout << ans << "\n";
    
    return 0;
}