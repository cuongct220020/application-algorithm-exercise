

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find next smaller for every element
vector<int> nextSmaller(vector<int> &hist, int n) {
    vector<int> nextS(n, n);   // Initialize with n for the cases when next smaller does not exist
    stack<int> ST;
    for (int i = 0; i < n; i++) {
        while (!ST.empty() && hist[i] < hist[ST.top()]) {
            nextS[ST.top()] = i; // Setting the index of the next smaller elementfor the top of the stack
            ST.pop();
        }
        ST.push(i);
    }
    return nextS;
}

// Function to find previous smaller for every element
vector<int> prevSmaller(vector<int> &hist, int n) {
    vector<int> prevS(n, -1); // Initialize with -1 for the cases when prev smaller does not exist
    stack<int> ST;
    for (int i = 0; i < n; i++) {
        while (!ST.empty() && hist[i] < hist[ST.top()]) {
            ST.pop(); // Setting the index of the previous smaller element for the top of the stack
        }
        if (!ST.empty()) {
            prevS[i] = ST.top();
        }
        ST.push(i);
    }
    return prevS;
}

int getMaxArea(vector<int> &hist, int n) {
    vector<int> prevS = prevSmaller(hist, n);
    vector<int> nextS = nextSmaller(hist, n);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nextS[i] - prevS[i] - 1;
        int area = hist[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> hist = {60, 20, 50, 40, 10, 50, 60};
    int n = hist.size();

    cout << getMaxArea(hist, n) << endl;

}
