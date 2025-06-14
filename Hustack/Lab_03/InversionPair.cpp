#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int n;
vector<long long> arr;

void input() {
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

long long count_and_merge(vector<long long> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<long long> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0;
    int k = left;
    long long result = 0;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k++] = R[j++];
            result = (result + (n1 - i)) % MOD;
        } else {
            arr[k++] = L[i++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    return result;
}

long long count_inversion(vector<long long> &arr, int left, int right) {
    long long count_pair = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count_pair = (count_pair + count_inversion(arr, left, mid)) % MOD;
        count_pair = (count_pair + count_inversion(arr, mid + 1, right)) % MOD;
        count_pair = (count_pair + count_and_merge(arr, left, mid, right)) % MOD;
    }
    return count_pair;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << count_inversion(arr, 0, n - 1) << endl;
    return 0;
}