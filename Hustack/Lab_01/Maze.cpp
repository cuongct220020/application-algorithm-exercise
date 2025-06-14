#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define N 999 + 5

typedef pair<int, int> ii;
int n, m, r, c;
int a[N][N];
queue<ii> Q;
int d[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; 
bool visited[N][N] = {};

int solve() {
    Q.push({r, c});
    d[r][c] = 0;
    visited[r][c] = true;
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];

            if (x < 1 || y < 1 || x > n || y > m) {
                return d[u.first][u.second] + 1;
            }

            if (a[x][y] == 0 && !visited[x][y]) {
                d[x][y] = d[u.first][u.second] + 1;
                Q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
    return -1;
}

void input() {
    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << solve() << endl;

    return 0;
}