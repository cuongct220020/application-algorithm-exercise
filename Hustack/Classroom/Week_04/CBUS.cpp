#include <iostream>
#include <vector>
using namespace std;

int n, K;
vector<vector<int>> c;
vector<int> x;
vector<bool> visited;
int c_min = INT_MAX;
int best = INT_MAX;
int load = 0;
int f_path = 0;

void input() {
    cin >> n >> K;
    c.resize(2 * n + 1, vector<int>(2 * n + 1, 0));
    x.resize(2 * n + 1);
    visited.resize(2 * n + 1, false);
    
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j)
                c_min = min(c_min, c[i][j]);
        }
    }
}

void updateBest() {
    if (f_path + c[x[2*n]][0] < best)
        best = f_path + c[x[2*n]][0];
}

bool check(int v, int k) {
    if (visited[v] == true) 
        return false;
    if (v > n && !visited[v - n])
        return false;
    if (v <= n && load + 1 > K)
        return false;
    return true;
}

void trySolve(int k) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(v, k)) {
            x[k] = v;
            f_path += c[x[k-1]][v];
            visited[v] = true;
            
            if (v <= n)
                load++;
            else
                load--;
            
            if (k == 2 * n) {
                updateBest();
            } else {
                if (f_path + c_min * (2 * n + 1 - k) < best)
                    trySolve(k + 1);
            }
            
            if (v <= n)
                load--;
            else
                load++;
            f_path -= c[x[k-1]][v];
            visited[v] = false;
        }
    }
} 

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    
    x[0] = 0;
    visited[0] = true;
    trySolve(1);

    cout << best << endl;
    return 0;
}