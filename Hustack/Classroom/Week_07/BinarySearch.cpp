#include <iostream>
#include <vector>
using namespace std;
// An interative binary search function
int binarySearch_1(vector<int> &a, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (x == a[mid])
            return mid;
        
        if (x > a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// A recursive binary search function
int binarySearch_2(vector<int> &a, int left, int right, int x) {
    if (right >= left) {
        int mid = (left + right) / 2;
        if (x == a[mid])
            return mid;
        
        if (x > a[mid])
            return binarySearch_2(a, mid + 1, right, x);
        
        if (x < a[mid])
            return binarySearch_2(a, left, mid - 1, x);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << binarySearch_2(a, 0, n - 1, x) << endl;

    return 0;
}