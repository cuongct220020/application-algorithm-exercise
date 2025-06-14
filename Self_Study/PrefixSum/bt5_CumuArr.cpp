#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> A(n + 1), C(n + 1);
    C[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        C[i] = C[i - 1] + A[i];
    }

    int Q;
    cin >> Q;
    for (int t = 1; t <= Q; t++) {
        int i, j;
        cin >> i >> j;
        int res = C[j] - C[i - 1];
        cout << res << endl;
    }

    return 0;
}