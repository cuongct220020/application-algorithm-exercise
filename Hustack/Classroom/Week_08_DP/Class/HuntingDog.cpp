#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dog {
    int weight;
    int intell;
    int value;
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<Dog> D(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> D[i].weight
            >> D[i].intell
            >> D[i].value;
    }

    sort(D.begin(), D.end(), [] (const Dog &p, const Dog &q) {
        if (p.weight != q.weight) {
            return p.weight < q.weight;
        }
        return p.intell > q.intell;
    });

    vector<int> dp(n + 1);
    
    int max_value = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = D[i].value;
        for (int j = 1; j < i; j++) {
            if (D[j].intell <= D[i].intell) {
                dp[i] = max(dp[i], dp[j] + D[i].value);
            }
        }
        max_value = max(max_value, dp[i]);
    }

    cout << max_value << endl;
    return 0;
}