#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    /* int curr_sum = a[1]; 
    int max_sum = a[1];
    for (int i = 2; i <= n; i++) {
        curr_sum = max(a[i], curr_sum + a[i]); // curr_sum luu tru trong so lon nhat cua i - 1 day truoc do
        max_sum = max(max_sum, curr_sum);
    }
    cout << max_sum << endl; */

    vector<int> dp(n + 1);
    dp[0] = 0;

    int max_sum = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(a[i], a[i] + dp[i - 1]);
        max_sum = max(max_sum, dp[i]);
    }
    cout << max_sum << endl;
    
    return 0;
}