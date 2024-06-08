// https://leetcode.cn/problems/maximum-students-taking-exam/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    a[i] |= 1 << j;
                }
            }
        }
        vector<vector<int>> mem(m, vector<int>(1 << n, -1));
        function<int(int, int)> dfs = [&](int i, int s) {
            int &ret = mem[i][s];
            if (ret != -1) return ret;
            if (i == 0) {
                int lb = s & -s;
                return ret = lb ? dfs(0, s & ~(3 * lb)) + 1 : 0;
            }
            ret = dfs(i - 1, a[i - 1]); // skip row i
            for (int j = s; j; j = (j - 1) & s) { // subset of s
                if ((j & (j >> 1)) == 0) { // !!! & is weaker than ==
                    ret = max(ret, dfs(i - 1, a[i - 1] & ~(j << 1 | j >> 1)) + __builtin_popcount(j));
                }
            }
            return ret;
        };
        return dfs(m - 1, a[m - 1]);
    }
};