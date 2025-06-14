#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num, low, child, khop;
vector<vector<int>> adj;
int timeDFS = 0;
int num_cau = 0, num_khop = 0;

void DFS(int u, int p) {
    num[u] = low[u] = timeDFS++;
    for (const auto v : adj[u]) {
        if (v != p) {
            if (!num[v]) {
                child[u]++;
                DFS(v, u);
                low[u] = min(low[u], low[v]);

                if (num[u] < low[v]) {
                    num_cau++;
                }

                if (p != 0 && num[u] <= low[v]) {
                    khop[u] = 1;
                }
            } else {
                low[u] = min(low[u], num[v]);
            }
        }
    }

    if (p == 0 && child[u] >= 2) khop[u] = 1; 
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    num.resize(n + 1, 0); 
    low.resize(n + 1, 0);
    child.resize(n + 1);
    khop.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            DFS(i, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        num_khop += khop[i];
    }

    cout << num_khop << " " << num_cau << "\n";

    return 0;
}