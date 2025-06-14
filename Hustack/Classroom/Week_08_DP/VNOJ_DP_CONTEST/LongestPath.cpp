#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n, m; // Number of vertices and edges
vector<int> g[N]; // Adjacency list
int dp[N]; // dp[i]: Longest path ending at node i
bool visited[N]; // Track visited nodes
vector<int> topoOrder; // Store topological ordering

// Topological Sort using DFS
void dfs(int u) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) dfs(v);
    }
    topoOrder.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;                // Convert to 0-indexed
        g[x].push_back(y);       // Add directed edge x -> y
    }

    // Step 1: Topological Sorting
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }
    reverse(topoOrder.begin(), topoOrder.end()); // Reverse the topo order

    // Step 2: Dynamic Programming on the DAG
    memset(dp, 0, sizeof(dp));  // Initialize dp array with 0
    int ans = 0;

    for (int u : topoOrder) {
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
        ans = max(ans, dp[u]); // Keep track of the longest path
    }

    // Step 3: Output the result
    cout << ans << "\n";

    return 0;
}
