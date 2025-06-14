#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
const int INF = 1e9 + 7;

int n, m, s, t;
vector<int> adj[N];
int c[N][N] = {0}, f[N][N] = {0}, parent[N];
int maxFlow = 0;

bool bfs() {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    
    q.push(s);
    parent[s] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (parent[v] == -1 && c[u][v] > f[u][v]) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    
    return false;
}

void augmentFlow() {
    int delta = INF;
    
    int v = t;
    while (v != s) {
        int u = parent[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    
    v = t;
    while (v != s) {
        int u = parent[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
    
    maxFlow += delta;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += cap;
    }
    
    while(bfs()) {
        augmentFlow();
    }
    
    cout << maxFlow << "\n";
    
    return 0;
}
