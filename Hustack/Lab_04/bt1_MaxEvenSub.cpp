#include <iostream>
#include <vector>
using namespace std;
const int INF = -1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<long long> S0(n + 1), S1(n + 1);

    if (a[1] % 2 == 0) {
        S0[1] = a[1];
        S1[1] = INF;
    } else {
        S0[1] = INF;
        S1[1] = a[1];
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) {
            S0[i] = max(a[i], a[i] + S0[i - 1]);
            S1[i] = (S1[i - 1] == INF) ? INF : (S1[i - 1] + a[i]);
        } else {
            S0[i] = (S1[i - 1] == INF) ? INF : (S1[i - 1] + a[i]);
            S1[i] = max(a[i], a[i] + S0[i - 1]);
        }
    }

    long long res = INF;
    for (int i = 1; i <= n; i++) {
        res = max(res, S0[i]);
    }

    if (res == INF) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}