#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e4 + 1;
int a[MAX_N], id[MAX_N];
int ST[MAX_N * 4];
int n, m;

struct Query
{
    int l, r, k, idx;
};

void build(int id, int l, int r)
{
    if (l == r)
    {
        ST[id] = 1;
        return;
    }

    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);

    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

void update(int id, int l, int r, int pos)
{
    if (pos < l || r < pos)
        return;

    if (l == r)
    {
        ST[id] = 0;
        return;
    }

    int m = (l + r) / 2;
    update(id * 2, l, m, pos);
    update(id * 2 + 1, m + 1, r, pos);

    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

int get(int id, int l, int r, int i, int j)
{
    if (j < l || r < i)
        return 0;

    if (i <= l && r <= j)
        return ST[id];

    int m = (l + r) / 2;
    return get(id * 2, l, m, i, j) + get(id * 2 + 1, m + 1, r, i, j);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }

    cin >> m;
    vector<Query> q(m);
    vector<int> res(m);

    for (int i = 0; i < m; i++)
    {
        cin >> q[i].l >> q[i].r >> q[i].k;
        q[i].idx = i;
    }

    sort(q.begin(), q.end(), [](const Query &q1, const Query &q2)
         { return q1.k < q2.k; });

    sort(id + 1, id + n + 1, [&](int i, int j)
         { return a[i] < a[j]; });

    build(1, 1, n);

    int i = 1;
    for (const auto &qi : q)
    {
        while (i <= n && a[id[i]] <= qi.k)
        {
            update(1, 1, n, id[i]);
            i++;
        }
        res[qi.idx] = get(1, 1, n, qi.l, qi.r);
    }

    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";

    return 0;
}
