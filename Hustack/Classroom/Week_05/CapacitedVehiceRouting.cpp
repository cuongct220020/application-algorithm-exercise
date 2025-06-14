#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, K, Q;
vector<int> d;
vector<vector<int>> c;
vector<int> x, y;
vector<bool> visited;
vector<int> load;
int c_min = INT_MAX;
int f_best = INT_MAX;
int f_path = 0;
int nbR = 0;
int segments = 0; 

void input() {
    cin >> n >> K >> Q;
    d.resize(n + 1, 0);
    c.resize(n + 1, vector<int> (n + 1, 0));
    x.resize(n + 1);
    y.resize(K + 1);
    visited.resize(n + 1, false);
    load.resize(K + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j)
                c_min = min(c_min, c[i][j]);
        }
    }
}

void updateBest() {
    if (f_path < f_best)
        f_best = f_path;
}

bool check_X(int v, int k) {
    if (v > 0 && visited[v])
        return false;
    
    if (load[k] + d[v] > Q)
        return false;
        
    return true;
}

void try_X(int s, int k) {
    if (s == 0) {
        if (k < K) {
            try_X(y[k + 1], k + 1);
        }
        return;
    }
    for (int v = 0; v <= n; v++) {
        if (check_X(v, k)) {
            x[s] = v;
            
            segments++;
            f_path += c[s][v];
            load[k] += d[v];
            visited[v] = true;
            
            if (v > 0) {
                if (f_path + (n + nbR - segments) * c_min < f_best)
                    try_X(v, k);
            } else {
                if (segments == n + nbR) {
                    updateBest();
                } else {
                    if (f_path + (n + nbR - segments) * c_min < f_best) {
                        try_X(y[k + 1], k + 1);
                    }
                }
            }
            
            segments--;
            f_path -= c[s][v];
            load[k] -= d[v];
            visited[v] = false;
        }
    }
}

bool check_Y(int v, int k) {
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    
    return true;
}

void try_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0)
        s = y[k - 1] + 1;
    
    for (int v = s; v <= n; v++) {
        if (check_Y(v, k)) {
            y[k] = v;
            
            if (v > 0)
                segments++;
            f_path += c[0][v];
            load[k] += d[v];
            visited[v] = true;
            
            if (k < K) {
                try_Y(k + 1);
            } else {
                nbR = segments;
                try_X(y[1], 1);
            }
            
            if (v > 0)
                segments--;
            f_path -= c[0][v];
            load[k] -= d[v];
            visited[v] = false;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();

    y[0] = 0;
    visited[0] = true;
    try_Y(1);
    
    cout << f_best << endl;

    return 0;
}