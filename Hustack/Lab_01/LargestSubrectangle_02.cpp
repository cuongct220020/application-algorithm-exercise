#include <iostream>
#include <stack>
using namespace std;

#define SIZE 1005
int n, m;
int a[SIZE][SIZE];
int h[SIZE];

int maxHist(int *h) {
    int result = 0;
    int width;
    stack<int> st;
    int tp, curr;

    for (int j = 0; j < m; j++) {
        while (!st.empty() && h[st.top()] >= h[j]) {
            tp = st.top();
            st.pop();
            width = st.empty() ? j : j - st.top() - 1;
            result = max(result, h[tp] * width);
        }
        st.push(j);
    }

    while (!st.empty()) {
        tp = st.top();
        st.pop();
        width = st.empty() ? m : m - st.top() - 1;
        result = max(result, h[tp] * width);
    }
    return result;
}

int getMaxSubRectangle(int a[SIZE][SIZE]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            h[j] = (a[i][j] == 1) ? h[j] + 1 : 0;
        }
        result = max(result, maxHist(h));
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << getMaxSubRectangle(a) << endl;
    
    return 0;
}
