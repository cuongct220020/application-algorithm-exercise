// https://oj.vnoi.info/problem/mink
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> minRange(n + 1, 0);

        deque<int> dq;

        for (int i = 1; i <= n; i++) {
            while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();

            dq.push_back(i);

            if (dq.front() + k <= i) dq.pop_front();

            if (i >= k) minRange[i] = a[dq.front()];
        }

        for (int i = k; i <= n; i++) {
            cout << minRange[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}