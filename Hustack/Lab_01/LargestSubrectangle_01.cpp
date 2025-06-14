#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getMaxHistArea(vector<int> &h, int m) {
    stack<int> st;
    int result = 0;
    int width = 0;
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

int getMaxSubrectangleArea(vector<vector<int>> &mt, int n, int m) {
    vector<int> h(m, 0);
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mt[i][j] == 1) {
                h[j] += 1;
            } else {
                h[j] = 0; // if we encounter the blank cell, we must reset h[j] = 0 because it have broken down the continuous structure of the sequence of black cells. 
            }
        }
        result = max(result, getMaxHistArea(h, m));
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mt(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    cout << getMaxSubrectangleArea(mt, n, m) << endl;
    return 0;
}