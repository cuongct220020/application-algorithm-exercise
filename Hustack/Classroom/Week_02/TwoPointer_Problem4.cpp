#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /* Two Pointer Technique */
    int res = 0, S = 0;
    int L = 0;
    for (int R = 0; R < n; R++) {
        S += a[R];
        while (S > Q) {
            S -= a[L];
            L++;
        }
        res = max(res, R - L + 1);
    }

    /* Direct Algorithm
    
    for (int i = 0; i < n; i++) {
        int S = 0;
        for (int j = i; j < n; j++) {
            S += a[j];
            if (S <= Q) {
                res = max(res, j-i+1);
            }
        }
    } */

    cout << res << endl;
    return 0;
}