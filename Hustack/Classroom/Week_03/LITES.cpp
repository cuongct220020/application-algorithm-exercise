// https://oj.vnoi.info/problem/lites
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int n, m;
int ST[4 * N] = {0};
int flag[4 * N] = {0};

void push(int id, int l, int r) {
    if (flag[id]) {
        int m = (l + r) / 2;
        flag[2 * id] ^= 1;
        flag[2 * id + 1] ^= 1;

        ST[2 * id] = (m - l + 1) - ST[2 * id];
        ST[2 * id + 1] = (r - m) - ST[2 * id + 1];

        flag[id] = 0;
    }
}

void update(int id, int l, int r, int x, int y) {
    if (y < l || x > r) return;

    if (x <= l && r <= y) {
        flag[id] ^= 1;
        ST[id] = (r - l + 1) - ST[id];
        return;
    }
    push(id, l, r);

    int m = (l + r) / 2;
    update(2 * id, l, m, x, y);
    update(2 * id + 1, m + 1, r, x, y);

    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

int get(int id, int l, int r, int x, int y) {
    if (y < l || x > r) return 0;
    
    if (x <= l && r <= y) {
        return ST[id];
    }
    push(id, l, r);

    int m = (l + r) / 2;
    int onLeft = get(2 * id, l, m, x, y);
    int onRight = get(2 * id + 1, m + 1, r, x, y);

    return onLeft + onRight;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    while (m--) {
        string tok;
        cin >> tok;

        if (tok == "0") {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
        }

        if (tok == "1") {
            int x, y;
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << "\n";
        } 
    }

    return 0;
}