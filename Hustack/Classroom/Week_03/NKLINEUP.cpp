// https://oj.vnoi.info/problem/nklineup
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 50001

int n, q;
int a[N];
int ST1[4 * N], ST2[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        ST1[id] = ST2[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2*id, l, m);
    build(2*id + 1, m + 1, r);

    ST1[id] = max(ST1[2*id], ST1[2*id + 1]);
    ST2[id] = min(ST2[2*id], ST2[2*id + 1]); 
}

int get_max(int id, int l, int r, int a, int b) {
    if (b < l || r < a) {
        return -INF;
    }
    if (a <= l && r <= b) {
        return ST1[id];
    }

    int m = (l + r) / 2;
    int max_left = get_max(2*id, l, m, a, b);
    int max_right = get_max(2*id + 1, m + 1, r, a, b);

    return max(max_left, max_right);
}

int get_min(int id, int l, int r, int a, int b) {
    if (b < l || r < a) {
        return INF;
    }
    if (a <= l && r <= b) {
        return ST2[id];
    }

    int m = (l + r) / 2;
    int min_left = get_min(2*id, l, m, a, b);
    int min_right = get_min(2*id + 1, m + 1, r, a, b);
    
    return min(min_left, min_right);
}

int get(int id, int l, int r, int a, int b) {
    return  get_max(id, l, r, a, b) 
            - get_min(id, l, r, a, b);
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    build(1, 1, n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << get(1, 1, n, a, b) << "\n";
    }

    return 0;
}