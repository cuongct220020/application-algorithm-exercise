#include <bits/stdc++.h>
using namespace std;

int maxDistSubSeq(int n, int c, vector<int> &x) {

}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, c;
        cin >> c >> c;

        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        cout << maxDistSubSeq(n, c, x) << "\n";
    }

    return 0;
}