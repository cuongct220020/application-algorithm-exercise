#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void merge(vector<int> &a, int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = a[first + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = first;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) {
        a[k++] = L[i++];
    }

    while (i < n2) {
        a[k++] = R[j++];
    }
}

void mergeSort(vector<int> &a, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
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
    mergeSort(a, 0, n - 1);
    printVector(a);
    return 0;
}