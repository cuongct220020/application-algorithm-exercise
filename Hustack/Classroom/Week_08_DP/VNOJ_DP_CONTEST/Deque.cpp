// https://oj.vnoi.info/problem/atcoder_dp_l
#include <bits/stdc++.h>
using namespace std;
#define MN 3001
using ll = long long;

int n;
ll dp1[MN], dp2[MN];
// dp1[i] = tổng số điểm tích luỹ lớn nhất tại bước thứ i của Taro
// dp2[i] = tổng số điểm tích luỹ lớn nhất tại bước thứ i của Jiro

// Khi i lẻ thì Taro được chọn
    // dp1[i] = max(dp1[i], dp1[i - 1] + max(dq.back(), dq.front())
    // dp2[i] = dp2[i - 1]

// Khi i chẵn thì Jiro được chọn
    // dp1[i] = dp1[i - 1]
    // dp2[i] = max(dp2[i], dp2[i - 1] + max(dq.back(), dq.front()))

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        dq.push_back(x);
    }

    dp1[0] = 0; dp2[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        if (dq.empty()) break;
        int f = dq.front();
        int b = dq.back();
        
        if (i % 2 != 0) // lượt của Taro
        {
            if (f > b) {
                dp1[i] = max(dp1[i], dp1[i - 1] + f);
                if (!dq.empty()) {
                    dq.pop_front();
                }

            } else {
                dp1[i] = max(dp1[i], dp1[i - 1] + b);
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
            
            dp2[i] = dp2[i - 1];

        } else { // lượt của Jiro
            if (f > b) {
                dp2[i] = max(dp2[i], dp2[i - 1] + f);
                if (!dq.empty()) {
                    dq.pop_front();
                }

            } else {
                dp2[i] = max(dp2[i], dp2[i - 1] + b);
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
            
            dp1[i] = dp1[i - 1];
        }
    }

    cout << (dp1[n] - dp2[n]) << "\n";
    return 0;
}