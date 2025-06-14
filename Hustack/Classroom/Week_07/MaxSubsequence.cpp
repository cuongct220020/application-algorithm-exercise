#include <iostream>
#include <vector>
using namespace std;

int maxLeftMid(vector<int> &a, int left, int mid) {
    int res = a[mid];
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += a[i];
        res = max(res, sum);
    }
    return res;
}

int maxRightMid(vector<int> &a, int mid, int right) {
    int res = a[mid];
    int sum = 0;
    for (int i = mid; i <= right; i++) {
        sum += a[i];
        res = max(res, sum);
    }
    return res;
}

int maxSubSeq (vector<int> &a, int left, int right) {
    if (left == right)
        return a[left];

    int mid = (left + right) / 2;
    int wL = maxSubSeq(a, left, mid);
    int wR = maxSubSeq(a, mid + 1, right);

    int wLM = maxLeftMid(a, left, mid);
    int wRM = maxRightMid(a, mid + 1, right);
    int wM = wLM + wRM;

   return max(max(wL, wR), wM);
}


int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << maxSubSeq(a, 0, n - 1) << endl;
    return 0;
}