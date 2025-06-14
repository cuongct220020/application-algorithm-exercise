// https://codeforces.com/contest/380/problem/C
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

char s[N];

typedef struct _Node {
    int opt_len, open, close;
    _Node(int opt = 0, int o = 0, int c = 0) : opt_len(opt), open(o), close(c) {}; 
} Node;

Node ST[4*N];

Node operator + (const Node &child_left, const Node &child_right) {
    Node res;
    int tmp = min(child_left.open, child_right.close);

    res.opt_len = child_left.opt_len + child_right.opt_len + tmp * 2;
    res.open = child_left.open + child_right.open - tmp;
    res.close = child_left.close + child_right.close - tmp;

    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') 
            ST[id] = Node(0, 1, 0);
        else 
            ST[id] = Node(0, 0, 1);
        
        return;
    }
    
    int m = (l + r) / 2;
    build(id*2, l, m);
    build(id*2 + 1, m+1, r);

    ST[id] = ST[id*2] + ST[id*2 + 1];
}

Node get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return Node(0, 0, 0);
    }
    
    if (u <= l && r <= v) {
        return ST[id];
    }

    int m = (l + r) / 2;
    Node left = get(id*2, l, m, u, v);
    Node right = get(id*2 + 1, m+1, r, u, v);

    return (left + right);
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int n = str.length();

    for (int i = 1; i <= n; i++) {
        s[i] = str[i - 1];
    }
    build(1, 1, n);

    int m;
    cin >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        Node res = get(1, 1, n, u, v);
        cout << res.opt_len << "\n";
    }

    return 0;
}