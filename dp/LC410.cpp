// https://leetcode.cn/problems/split-array-largest-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < n; ++j) {
                for (int l = i; l <= j; ++l) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][l], pref[j + 1] - pref[l]));
                }
            }
        }
        return dp[k][n];
    }
};