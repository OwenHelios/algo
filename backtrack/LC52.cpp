// https://leetcode.cn/problems/n-queens-ii/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n);
        vector<bool> diag1(2 * n - 1);
        vector<bool> diag2(2 * n - 1);
        function<int(int)> dfs = [&](int i) {
            if (i == n) return 1;
            int ret = 0;
            for (int j = 0; j < n; ++j) {
                int d1 = i - j + n - 1;
                int d2 = i + j;
                if (cols[j] || diag1[d1] || diag2[d2]) continue;
                cols[j] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                ret += dfs(i + 1);
                cols[j] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
            return ret;
        };
        return dfs(0);
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        function<int(int, int, int, int)> dfs = [&](int i, int cols, int diag1, int diag2) {
            if (i == n) {
                return 1;
            }
            int ret = 0;
            int usableCols = (1 << n) - 1 & ~(cols | diag1 | diag2);
            while (usableCols) {
                int lb = usableCols & -usableCols;
                usableCols -= lb;
                ret += dfs(i + 1, cols | lb, (diag1 | lb) << 1, (diag2 | lb) >> 1);
            }
            return ret;
        };
        return dfs(0, 0, 0, 0);
    }
};