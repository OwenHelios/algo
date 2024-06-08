// https://leetcode.cn/problems/selling-pieces-of-wood/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (auto &p : prices) {
            dp[p[0]][p[1]] = p[2]; // not cutting
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 1; k <= i / 2 + 1; ++k) {
                    // first cut horizontal
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[k][j + 1] + dp[i + 1 - k][j + 1]);
                }
                for (int k = 1; k <= j / 2 + 1; ++k) {
                    // first cut vertical
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][k] + dp[i + 1][j + 1 - k]);
                }
            }
        }
        return dp[m][n];
    }
};