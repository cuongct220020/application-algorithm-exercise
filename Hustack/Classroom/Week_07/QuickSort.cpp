#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int n;
vector<int> arr;

void input() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArr(vector<int> arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

/* Lomuto Partition Scheme */
int partition_1(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

/* Hoare's Partition Scheme*/
int partition_2(vector<int> &arr, int left, int right) {
    srand(time(0));
    int random = left + rand() % (right - left + 1);
    int pivot = arr[random];
    swap(arr[random], arr[left]);

    int i = left; 
    int j = right + 1;
    while (i < j) {
        do {
            i++;
        } while (i <= right && arr[i] <= pivot);

        do {
            j--;
        } while (j >= left && arr[j] > pivot);

        if (i >= j) {
            break;
        }

        swap(arr[i], arr[j]);
    }

    swap(arr[j], arr[left]);
    return j;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = partition_2(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    quickSort(arr, 0, n - 1);
    printArr(arr);
    return 0;
}