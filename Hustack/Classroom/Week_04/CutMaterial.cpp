#include <iostream>
#include <vector>
using namespace std;

int H, W, n;
vector<int> h, w;
vector<vector<bool>> marked;
bool found_solution = false; 

void input() {
    cin >> H >> W;
    cin >> n;
    h.resize(n);
    w.resize(n);
    marked.resize(H, vector<bool>(W, false));
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }
}

void doMark(int vx, int vy, int hk, int wk, bool mark_value) {
    for (int i = vx; i < vx + hk; i++) {
        for (int j = vy; j < vy + wk; j++) {
            marked[i][j] = mark_value;
        }
    }
}

bool check(int vx, int vy, int hk, int wk) {
    if (vx + hk > H || vy + wk > W)
        return false; 

    for (int i = vx; i < vx + hk; i++) {
        for (int j = vy; j < vy + wk; j++) {
            if (marked[i][j])
                return false;
        }
    }
    return true;
}

void trySolve(int k) {
    if (found_solution) return;

    for (int vo = 0; vo <= 1; vo++) {
        int hk = h[k];
        int wk = w[k];
        if (vo == 1) swap(hk, wk);

        for (int vx = 0; vx <= H - hk; vx++) {
            for (int vy = 0; vy <= W - wk; vy++) {
                if (check(vx, vy, hk, wk)) {
                    doMark(vx, vy, hk, wk, true);
                    
                    if (k == n - 1) {
                        found_solution = true;
                        return;
                    } else {
                        trySolve(k + 1);
                    }

                    doMark(vx, vy, hk, wk, false);
                }
            }
        }        
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    trySolve(0);
    if (found_solution) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
