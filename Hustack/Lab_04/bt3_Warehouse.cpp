#include <iostream>
#include <vector>
using namespace std;
int N, T, D;
vector<int> a, t;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T >> D;
    a.resize(N + 1);
    t.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }

    // DP[i][j] = số lượng hàng hoá lớn nhất bốc được tại kho cuối cùng j và trong thời gian i
    vector<vector<int>> DP;
    DP.resize(T + 1, vector<int> (N + 1, 0));

    for (int i = 1; i <= N; i++) {
        if (t[i] <= T) {
            DP[t[i]][i] = a[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= N; j++) {
            if (DP[i][j] == 0) continue;
                
            for (int k = j + 1; k <= j + D && k <= N; k++) {
                if (i + t[k] <= T) {
                    DP[i + t[k]][k] = max(DP[i + t[k]][k], a[k] + DP[i][j]);
                }
            }

            ans = max(ans, DP[i][j]);
        }
    }
    cout << ans << "\n";

    return 0;
}