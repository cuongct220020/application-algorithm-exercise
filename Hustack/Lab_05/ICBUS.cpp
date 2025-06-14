#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
const int INF = 1e9 + 7;

int n, m, D[N], C[N];
vector<int> adj[N];

typedef struct Node {
    int dist, d, u;
    
    bool operator > (const Node &other) const {
        return dist > other.dist;        
    }
} Node;

int dijkstra() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    bool visited[N][101] = {false};
    vector<vector<int>> dist(N, vector<int> (101, INF));
    
    dist[1][D[1]] = C[1];
    pq.push({dist[1][D[1]], D[1], 1});
    
    while (!pq.empty()) {
        Node x = pq.top();
        pq.pop();
        
        int u = x.u;
        int d_u = x.d;
        int dist_u = x.dist;
        
        if (u == n) return dist_u;
        if (visited[u][d_u]) continue;
        
        for (int v : adj[u]) {
            if (d_u > 0 && dist[v][d_u - 1] > dist[u][d_u]) {
                dist[v][d_u - 1] = dist[u][d_u];
                pq.push({dist[v][d_u - 1], d_u - 1, v});
            }
            if (dist[v][D[v]] > dist[u][d_u] + C[v]) {
                dist[v][D[v]] = dist[u][d_u] + C[v];
                pq.push({dist[v][D[v]], D[v], v});
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << dijkstra() << "\n";
    return 0;
}