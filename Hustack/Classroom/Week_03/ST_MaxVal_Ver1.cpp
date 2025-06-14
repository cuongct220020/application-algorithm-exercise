#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
const int N = 1e5;
int A[N], ST[4*N];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = A[l];
        return;
    }

    int m = (l + r) / 2;
    build(id*2, l, m);
    build(id*2 + 1, m+1, r);
    
    ST[id] = max(ST[id*2], ST[id*2 + 1]);
}

void update(int id, int l, int r, int pos, int v) {
    if (pos > r || pos < l) {
        return;
    }
    
    if (l == r) {
        ST[id] = v;
        return;
    }
    
    int m = (l + r) / 2;
    update(id*2, l, m, pos, v);
    update(id*2 + 1, m+1, r, pos, v);
    ST[id] = max(ST[id*2], ST[id*2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) {
        return -INF;
    }
    if (u <= l && r <= v) {
        return ST[id];
    }
    
    int m = (l + r) / 2;
    int left = get(id*2, l, m, u, v);
    int right = get(id*2 + 1, m+1, r, u, v);
    return max(left, right);
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    build(1, 1, n);

    int m;
    cin >> m;
    
    string tok;
    while (m--) {
        cin >> tok;
        if (tok == "get-max") {
            int u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
        
        if (tok == "update") {
            int pos, v;
            cin >> pos >> v;
            update(1, 1, n, pos, v);
        }
    }

    return 0;
}
