#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("bt6_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n + 1, vector<int> (m + 1));
    vector<vector<int>> C(n + 1, vector<int> (m + 1));
    
    C[0][0] = 0; C[0][1] = 0; C[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            C[i][j] = A[i][j] + C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
        }
    }

    int Q;
    cin >> Q;
    for (int t = 1; t <= Q; t++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int res = C[r2][c2] - C[r2][c1 - 1] - C[r1 - 1][c2] + C[r1 - 1][c1 - 1];
        cout << res << endl;
    }

    return 0;
}