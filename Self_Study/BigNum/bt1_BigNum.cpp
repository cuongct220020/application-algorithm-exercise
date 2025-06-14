// http://uva.onlinejudge.org/external/4/424.html

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(const string &str1, const string &str2) {
    string result = "";
    int l1 = str1.size();
    int l2 = str2.size();

    int i = l1 - 1, j = l2 - 1;
    int carry = 0;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? (str1[i--] - '0') : 0;
        int digit2 = (j >= 0) ? (str2[j--] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result += (sum % 10) + '0';
        carry = sum / 10; 
    }

    reverse(result.begin(), result.end()); // 370370367037037036703703703670
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string total = "";
    string input;
    
    while (true) {
        cin >> input;
        if (input == "0") break;
        total = add(total, input);
    }

    cout << total << endl;
    return 0;
}

