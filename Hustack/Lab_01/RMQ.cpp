#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define N 1000000
int a[N];
int M[30][N];
int n, m;

int RMQ(int i, int j) {
    int k = log2(j - i + 1);
    if (a[M[k][i]] <= a[M[k][j - (1 << k) + 1]]) {
        return a[M[k][i]];
    } else {
        return a[M[k][j - (1 << k) + 1]];
    }
}

// M[i][j] luu chi so cua pt nho nhat cua chuoi bat dau tu j va co 2^i ptu

// neu ptu cua chuoi con ben trai nho hon pt cua chuoi con ben phai thi M[i][j] se luu chi so cua cua pt nho nha ben trai va nguoc lai. 
void preprocessing() {
    for (int j = 0; j < n; j++) {
        M[0][j] = j;
    }
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            if (a[M[i-1][j]] < a[M[i-1][j + (1 << (i-1))]]) {
                M[i][j] = M[i-1][j];
            } else {
                M[i][j] = M[i-1][j + (1 << (i-1))];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    preprocessing();
    cin >> m;
    int sum = 0;
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        sum += RMQ(i, j);
    }

    cout << sum << endl;

    return 0;
}