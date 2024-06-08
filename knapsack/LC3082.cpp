// https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences/
#include <bits/stdc++.h>

using namespace std;

// 2 dimensional 0-1
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = (1ll * dp[i - 1][j] * 2 + dp[i - 1][j - nums[i - 1]]) % MOD;
                } else {
                    dp[i][j] = 1ll * dp[i - 1][j] * 2 % MOD;
                }
            }
        }
        return dp[n][k];
    }
};