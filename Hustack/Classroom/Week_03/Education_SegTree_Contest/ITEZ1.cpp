#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
const int N = 1e5;

int n, q;
int a[N], ST[4*N];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l];
        return;
    }
    
    int m = (l + r) / 2;
    build(2*id, l, m);
    build(2*id + 1, m + 1, r);
    
    ST[id] = max(ST[2*id], ST[2*id + 1]);
}

void update(int id, int l, int r, int pos, int y) {
    if (pos < l || pos > r) {
        return;
    }
    
    if (l == r) {
        ST[id] = y;
        return;
    }
    
    int m = (l + r) / 2;
    update(2*id, l, m, pos, y);
    update(2*id + 1, m + 1, r, pos, y);
    
    ST[id] = max(ST[2*id], ST[2*id + 1]);
}

int get(int id, int l, int r, int x, int y) {
    if (y < l || x > r) {
        return -INF;
    }
    
    if (x <= l && r <= y) {
        return ST[id];
    }
    
    int m = (l + r) / 2;
    int maxLeft = get(2*id, l, m, x, y);
    int maxRight = get(2*id + 1, m + 1, r, x, y);
    return max(maxLeft, maxRight);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    
    cin >> q;
    while (q--) {
        string tok;
        cin >> tok;
        
        if (tok == "1") {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
        }
        
        if (tok == "2") {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
    
    return 0;
}
