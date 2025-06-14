#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n, 0); 
    //map<int, int> M;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            prefix[i] = prefix[i-1] + a[i];
        } else {
            prefix[i] = a[i];
        }
    }

    int Q;
    cin >> Q;
    int i, j;

    for (int k = 0; k < Q; k++) {
        cin >> i >> j;
        --i;
        --j;
        //M[k] = prefix[j] - prefix[i-1];
        cout << prefix[j] - prefix[i-1] << endl;
    }

    /* for (int k = 0; k < Q; k++) {
        cout << M[k] << endl;
    } */

    return 0;
}