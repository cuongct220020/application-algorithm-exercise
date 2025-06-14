#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int m, n; // m teachers, n courses
vector<int> X, load;
vector<vector<int>> T; // T[i] is a list of teachers can be assigned for course i. 
vector<vector<bool>> conflicts;
int opt_load = INT_MAX;

void input() {
    cin >> m >> n;
    
    load.resize(m + 1, 0);
    X.resize(n + 1, 0);
    T.resize(n + 1);
    conflicts.resize(n + 1, vector<bool> (n + 1, false));

    int k, course;
    for (int t = 1; t <= m; t++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> course;
            T[course].push_back(t);
        }
    }

    cin >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        conflicts[u][v] = conflicts[v][u] = true;
    }
}

void updateBest() {
    int max_load = 0;
    for (int t = 1; t <= m; t++) {
        max_load = max(max_load, load[t]);
    }
    if (max_load < opt_load) {
        opt_load = max_load;
    }
}


bool check(int t, int k) {
    for (int i = 1; i < k; i++) {
        if (X[i] == t && conflicts[i][k]) {
            return false;
        }
    }
    return true;
}

void Try(int k) {
    for (int t : T[k]) {
        if (check(t, k)) {
            X[k] = t;
            load[t]++;

            if (k == n) {
                updateBest();
            } else {
                if (load[t] < opt_load)
                    Try(k + 1);
            }

            load[t]--;
        }
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    Try(1);
    
    if (opt_load == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << opt_load << endl;
    }
    return 0;
}
