#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
using ll = long long;

int n, m;
ll ST[4 * N] = {0};

void update(int id, int l, int r, int pos, int y) {
    if (pos < l || pos > r) return;

    if (l == r) {
        ST[id] = y;
        return;
    }
    
    int m = (l + r) / 2;
    update(2 * id, l, m, pos, y);
    update(2 * id + 1, m + 1, r, pos, y);

    ST[id] = ST[2 * id] + ST[2 * id + 1];
}

ll get(int id, int l, int r, int x, int y) {
    if (y < l || x > r) return 0;

    if (x <= l && r <= y) return ST[id];

    int m = (l + r) / 2;
    ll sumLeft = get(2 * id, l, m, x, y); 
    ll sumRight = get(2 * id + 1, m + 1, r, x, y);

    return sumLeft + sumRight;
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