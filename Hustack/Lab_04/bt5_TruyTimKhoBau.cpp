#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MIN;
using ll = long long;
typedef struct Point {
    int x, y, c;
} P;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    
    vector<P> kho_bau;
    kho_bau.push_back({0, 0, 0});
    
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        kho_bau.push_back({x, y, c});
    }
    
    sort(kho_bau.begin(), kho_bau.end(), [] (P kb1, P kb2) {
        if (kb1.x == kb2.x) {
            return kb1.y < kb2.y;
        }
        return kb1.x < kb2.x;
    });
    
    // dp[i]: tong luong vang lon nhat thu duoc tai vi tri i
    vector<ll> dp(n + 1, INF);
    
    for (int i = 0; i <= n; i++) {
        dp[i] = kho_bau[i].c;
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (kho_bau[j].x >= kho_bau[i].x && kho_bau[j].y >= kho_bau[i].y) {
                dp[j] = max(dp[j], kho_bau[j].c + dp[i]);
            }
        }
    }
    
    ll ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";
    
    return 0;
}
