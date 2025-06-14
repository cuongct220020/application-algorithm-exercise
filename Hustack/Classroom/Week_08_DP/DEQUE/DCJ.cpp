// https://codeforces.com/contest/1407/problem/D
#include <bits/stdc++.h>
using namespace std;
#define MN 300006
int N; 
int H[MN], L[MN], R[MN], l[MN], r[MN];

vector<int> adj[MN];

void input() {
    // Input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
}

void build() {
    deque<int> dq;

    // l[k] = cot xa nhat ben trai nhan H[k] la min
    // dq.clear();
    for (int k = 1; k <= N; k++) {
        while (!dq.empty() && H[dq.back()] >= H[k]) dq.pop_back();

        l[k] = (dq.empty()) ? 1 : dq.back() + 1;

        dq.push_back(k);
    }

    // r[k] = cot xa nhat ben phai nhat H[k] la min
    dq.clear();
    for (int k = N; k >= 1; k--) {
        while (!dq.empty() && H[dq.back()] >= H[k]) dq.pop_back();

        r[k] = (dq.empty()) ? N : dq.back() - 1;

        dq.push_back(k);
    }

    // L[k] = cot xa nhat ben trai nhan H[k] la max
    dq.clear();
    for (int k = 1; k <= N; k++) {
        while (!dq.empty() && H[dq.back()] <= H[k]) dq.pop_back();

        L[k] = (dq.empty()) ? 1 : dq.back() + 1;

        dq.push_back(k);
    }

    // R[k] = cot xa nhat ben phai nhan H[k] la max
    dq.clear();
    for (int k = N; k >= 1; k--) {
        while (!dq.empty() && H[dq.back()] <= H[k]) dq.pop_back();

        R[k] = (dq.empty()) ? N : dq.back() - 1;

        dq.push_back(k);
    }
}

void graph() {
    for (int i = 1; i < N; i++) {
        adj[i].push_back(i + 1);
    }

    for (int k = 1; k <= N; k++) {
        if (H[k] < min(H[L[k] - 1], H[R[k] + 1])) {
            adj[L[k] - 1].push_back(R[k] + 1);
        }
    }

    for (int k = 1; k <= N; k++) {
        if (H[k] > max(H[l[k] - 1], H[r[k] + 1])) {
            adj[l[k] - 1].push_back(r[k] + 1);
        }
    }
}

int bfs(int s, int t) {
    queue<int> q;
    vector<int> dist(N + 1, -1);
    vector<bool> visited(N + 1, false);

    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (const auto &v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;

                if (v == t) {
                    return dist[v];
                }
            }
        }
    }

    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    build();
    graph();

    cout << bfs(1, N) << "\n";

    return 0;
}