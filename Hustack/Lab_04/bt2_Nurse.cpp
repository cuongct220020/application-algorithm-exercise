#include <iostream>
#include <cstring>
#define N_MAX 1001
const int MOD = 1e9 + 7;
using namespace std;

int N, K1, K2;
int S0[N_MAX], S1[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K1 >> K2;
    S0[0] = S0[1] = 1;
    S0[K1] = 0; S1[K1] = 1;
    for (int i = K1 + 1; i <= N; i++) {
        S0[i] = S1[i - 1] % MOD;

        S1[i] = 0;
        for (int j = K1; j <= K2; j++) {
            if (i - j >= 0) {
                S1[i] = (S1[i] + S0[i - j]) % MOD;
            }
        }
    } 

    int res = (S0[N] + S1[N]) % MOD;
    cout << res << endl;

    return 0;
}
