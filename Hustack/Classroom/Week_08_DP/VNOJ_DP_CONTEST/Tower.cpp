// https://oj.vnoi.info/problem/atcoder_dp_x
#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef struct _Block {
    int w, s, v;
} Block;

int n;
vector<Block> B;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> B[i].w >> B[i].s >> B[i].v;
    }

    sort(B.begin(), B.end(), [] (const Block &b1, const B) {

    });

    return 0;
}