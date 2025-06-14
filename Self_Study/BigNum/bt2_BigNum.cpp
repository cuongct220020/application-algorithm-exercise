#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct bigNum {
    char sign;
    string num;  
};

bool compare(const bigNum &a, const bigNum &b) {
    if (a.num.size() != b.num.size()) 
        return a.num.size() > b.num.size();
    return a.num > b.num;
}

string add(const string str1, const string str2) {
    string res = "";
    int l1 = str1.size(), l2 = str2.size();
    int i = l1 - 1, j = l2 - 1;
    int carry = 0;

    while (i >= 0 || j >= 0) {
        int a = (i >= 0) ? (str1[i--] - '0') : 0;
        int b = (j >= 0) ? (str2[j--] - '0') : 0;

        int sum = a + b + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string subt(const string str1, const string str2) {
    string res = "";
    int l1 = str1.size(), l2 = str2.size();
    int i = l1 - 1, j = l2 - 1;
    int borrow = 0;

    while (i >= 0 || j >= 0) {
        int a = (i >= 0) ? (str1[i--] - '0') : 0;
        int b = (j >= 0) ? (str2[j--] - '0') : 0;

        int sub = a - b - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res += sub + '0';
    }

    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res;
}

bigNum operator + (const bigNum &a, const bigNum &b) {
    bigNum res;
    if (a.sign == b.sign) {
        res.sign = a.sign;
        res.num = add(a.num, b.num);
    } else {
        if (compare(a, b)) {
            res.sign = a.sign;
            res.num = subt(a.num, b.num);
        } else {
            res.sign = b.sign;
            res.num = subt(b.num, a.num);
        }
    }
    
    return res;
}

bigNum operator - (const bigNum &a, const bigNum &b) {
    bigNum res;

    if (a.sign != b.sign) {
        res.sign = a.sign;
        res.num = add(a.num, b.num);
    } else {
        if (compare(a, b)) {
            res.sign = a.sign;
            res.num = subt(a.num, b.num);
        } else {
            res.sign = (a.sign == '1') ? '0' : '1';
            res.num = subt(b.num, a.num);
        }
    }

    return res;
}

int main() {
    freopen("bt2_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bigNum a, b, c, result;
    cin >> a.sign >> a.num;
    cin >> b.sign >> b.num;
    cin >> c.sign >> c.num;

    // Tính biểu thức a + b - c
    result = a + b - c; // 0975308643197

    cout << result.sign << result.num << endl;
    return 0;
}
