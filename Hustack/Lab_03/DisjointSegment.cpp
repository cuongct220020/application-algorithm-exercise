#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
int n;
vector<ii> C;
int count_seg = 0;

void input() {
    cin >> n;
    C.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i].first >> C[i].second;
    }
}

void solution() {
    cout << count_seg << endl;
}

bool feasible(ii i, int last_end) {
    if (last_end < i.first)
        return true;
    
    return false;
}

void greedy() {
    sort(C.begin(), C.end(), [] (ii a, ii b) {
        return a.second < b.second;
    });

    int last_end = -1;
    for (auto i : C) {
        if (feasible(i, last_end)) {
            count_seg++;
            last_end = i.second;
        }
    }

    solution();
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    greedy();

    return 0;
}