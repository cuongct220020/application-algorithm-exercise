#include <iostream>
#include <vector>
using namespace std;
int n, M;
int sum = 0;
int count = 0;
vector<int> a;
vector<int> X;

void input() {
    cin >> n >> M;
    a.resize(n + 1, 0);
    X.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

bool check(int v, int k) {
    return true;
}

void trySolve(int k) {
    for (int v = 1; v <= M / a[k]; v++) {
        if (check(v, k)) {
            X[k] = v;
            sum += a[k] * X[k];
            
            if (k == n && sum == M) {
                count++;
            } else if (k < n && sum < M) {
                trySolve(k + 1);
            }

            sum -= a[k] * X[k];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    trySolve(1);
    cout << count << endl;
    return 0;
}