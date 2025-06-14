#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, M;
    cin >> n >> M;
    vector<vector<int>> c;
    c.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> dp;

    int maxS = 1 << n;
    dp.resize(maxS, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int S = 0; S < maxS; S++)
    {
        for (int i = 0; i < n; i++)
        {
            if (S & (1 << i))
            {
                for (int j = 0; j < n; j++)
                {
                    if (!(S & (1 << j)))
                    {
                        dp[S | (1 << j)][j] = min(dp[S | (1 << j)][j], dp[S][i] + c[i][j]);
                    }
                }
            }
        }
    }

    int opt_cost = INF;
    for (int i = 1; i < n; i++)
    {
        opt_cost = min(opt_cost, dp[maxS - 1][i] + c[i][0]);
    }
    cout << opt_cost << endl;

    return 0;
}