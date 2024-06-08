// https://leetcode.cn/problems/n-queens/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n);
        vector<bool> diag1(2 * n - 1);
        vector<bool> diag2(2 * n - 1);
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(cur);
                return;
            };
            int ret = 0;
            for (int j = 0; j < n; ++j) {
                int d1 = i - j + n - 1;
                int d2 = i + j;
                if (cols[j] || diag1[d1] || diag2[d2]) continue;
                cur[i][j] = 'Q';
                cols[j] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                dfs(i + 1);
                cur[i][j] = '.';
                cols[j] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        };
        dfs(0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n);
        vector<bool> diag1(2 * n - 1);
        vector<bool> diag2(2 * n - 1);
        vector<vector<string>> ans;
        vector<string> cur;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(cur);
                return;
            };
            int ret = 0;
            string s(n, '.');
            for (int j = 0; j < n; ++j) {
                int d1 = i - j + n - 1;
                int d2 = i + j;
                if (cols[j] || diag1[d1] || diag2[d2]) continue;
                s[j] = 'Q';
                cur.push_back(s);
                cols[j] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                dfs(i + 1);
                s[j] = '.';
                cur.pop_back();
                cols[j] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        };
        dfs(0);
        return ans;
    }
};