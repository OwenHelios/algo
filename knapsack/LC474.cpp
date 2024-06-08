// https://leetcode.cn/problems/ones-and-zeroes/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string &s : strs) {
            int c0 = count(s.begin(), s.end(), '0');
            int c1 = count(s.begin(), s.end(), '1');
            for (int i = m; i >= c0; --i) {
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};