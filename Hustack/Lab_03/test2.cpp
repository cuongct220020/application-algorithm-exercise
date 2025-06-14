#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [] (pii seg1, pii seg2) {
        return seg1.second < seg2.second;
    });
    
    vector<pii> S;
    for (int i = 1; i <= n; i++) {
        if (S.empty()) {
            S.push_back({a[i].first, a[i].second});
        } else {
            if (S.back().second < a[i].first) {
                S.push_back({a[i].first, a[i].second});
            }
        }
    }
    
    cout << S.size() << "\n";

    return 0;
}