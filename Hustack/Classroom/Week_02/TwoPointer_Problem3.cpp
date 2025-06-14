#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    int first = 0;
    int last = n-1;

    while (first < last) {
        if (a[first] + a[last] == M) {
            count++;
            first++;
            last--;
        } else if (a[first] + a[last] < M) {
            first++;
        } else {
            last--;
        }
    }
    cout << count << endl;
    return 0;
}