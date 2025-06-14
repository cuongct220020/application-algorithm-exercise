#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define N 21
#define INF 1e9
int n;
int c[N][N];
int mem[N][1 << N];

int TSP_DP(int i, int S) {
    if (S == (1 << n) - 1) 
        return mem[i][S] = c[i][0];

    if (mem[i][S] != -1) 
        return mem[i][S];

    int res = INF;
    for (int j = 0; j < n; j++) {
        if (S & (1 << j)) 
            continue;

        res = min(res, c[i][j] + TSP_DP(j, S | (1 << j)));
    }
    mem[i][S] = res;

    return res;
}

int main() {
    memset(mem, -1, sizeof(mem));
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    cout << TSP_DP(0, 1) << endl;

    return 0;
}