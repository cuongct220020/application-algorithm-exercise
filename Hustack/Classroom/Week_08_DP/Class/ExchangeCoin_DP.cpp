#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    
    vector<int> D(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
    }

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    
    for (int i = 1; i <= n; i++) {
        for (int j = D[i]; j <= x; j++) {
            dp[j] = min(dp[j], 1 + dp[j - D[i]]);
        }
    }

    cout << ((dp[x] != INF) ? dp[x] : -1) << endl;
    return 0;
}
