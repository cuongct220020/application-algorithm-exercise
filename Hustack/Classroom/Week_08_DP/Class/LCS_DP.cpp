#include <iostream>
#include <vector>
using namespace std;
using vii = vector<vector<int>>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vi X(n + 1), Y(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> Y[j];
    }
    
    vii dp(n + 1, vi (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}