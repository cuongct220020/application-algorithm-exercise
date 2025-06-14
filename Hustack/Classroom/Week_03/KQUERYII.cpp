// https://oj.vnoi.info/problem/kquery2
// https://wiki.vnoi.info/algo/data-structures/fenwick
#include <bits/stdc++.h>
using namespace std;

#define N 30001
const int MAX_VAL = 10000;

int n, m, a[N];
int block_size = ceil(sqrt(N));
vector<vector<int>> BIT(block_size + 1, vector<int>(MAX_VAL + 1));

// Hàm cập nhật giá trị trong Fenwick Tree
void updateBIT(int id, int x, int val) {
    for (; x <= MAX_VAL; x += x & -x) {
        BIT[id][x] += val;
    }
}

// Hàm truy vấn tổng tiền tố trong Fenwick Tree
int queryBIT(int id, int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x) {
        sum += BIT[id][x];
    }
    return sum;
}

// Hàm build Fenwick Tree cho các block
void build(int id, int l, int r) {
    for (int i = l; i <= r; ++i) {
        updateBIT(id, a[i], 1);
    }
}

// Hàm cập nhật giá trị tại vị trí i thành v
void update(int i, int v) {
    int block_id = i / block_size + 1;
    int val = a[i];
    // Cập nhật lại các Fenwick Tree của block chứa i và các block cha
    while (block_id) {
        updateBIT(block_id, val, -1); // Trừ đi giá trị cũ
        block_id /= 2;
    }
    val = v;
    block_id = i / block_size + 1;
    while (block_id) {
        updateBIT(block_id, val, 1);  // Cộng thêm giá trị mới
        block_id /= 2;
    }
    a[i] = v;
}

// Hàm tìm số lượng số nhỏ hơn hoặc bằng k trong đoạn [l, r]
int get(int l, int r, int k) {
    int block_size = sqrt(n);
    int left_block = l / block_size + 1;
    int right_block = r / block_size + 1;
    int ans = 0;

    // Xử lý các phần tử trong các block hoàn chỉnh
    if (left_block == right_block) {
        for (int i = l; i <= r; ++i) {
            ans += a[i] <= k;
        }
    } else {
        for (int i = left_block + 1; i < right_block; ++i) {
            ans += queryBIT(i, k);
        }
        // Xử lý phần đầu và cuối của đoạn
        for (int i = l; i <= (left_block + 1) * block_size - 1; ++i) {
            ans += a[i] <= k;
        }
        for (int i = right_block * block_size; i <= r; ++i) {
            ans += a[i] <= k;
        }
    }

    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> m;
    while (m--) {
        string tok;
        cin >> tok;

        if (tok == "0") {
            int i, v;
            cin >> i >> v;
            update(i, v);
        }

        if (tok == "1") {
            int i, j, k;
            cin >> i >> j >> k;
            cout << get(i, j, k) << "\n";
        }
    }

    return 0;
}