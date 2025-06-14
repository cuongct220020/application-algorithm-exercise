/* Naive Approach - O(n^2) time and O(1) space */
#include <iostream>
using namespace std;

int getMaxArea(int hist[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        int curr = hist[i];

        for (int j = i - 1; j >= 0 && hist[j] >= hist[i]; j--) {
            curr += hist[i];
        }

        for (int j = i + 1; j < n && hist[j] >= hist[i]; j++) {
            curr += hist[i];
        }

        result = max(result, curr);
    }

    return result;
}

int main() {
    int hist[] = {60, 20, 50, 40, 10, 50, 60};
    int n = sizeof(hist) / sizeof(hist[0]);
    cout << getMaxArea(hist, n) << endl;
    return 0;
}
