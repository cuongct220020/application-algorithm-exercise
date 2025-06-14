#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int> (m + 1, 0));
    vector<vector<int>> S(n + 1, vector<int>(m + 1, 0));
    map<int, int> M;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
        }
    }
    
    int Q;
    cin >> Q;
    int r1, c1, r2, c2;
    for (int k = 0; k < Q; k++) {
        cin >> r1 >> c1 >> r2 >> c2;
        M[k] =  S[r2][c2] 
                    - (r1 > 1 ? S[r1 - 1][c2] : 0) 
                    - (c1 > 1 ? S[r2][c1-1] : 0)
                    + (r1 > 1 && c1 > 1 ? S[r1-1][c1-1] : 0);
    }
    for (int k = 0; k < Q; k++) {
        cout << M[k] << endl;
    }

    return 0;
}