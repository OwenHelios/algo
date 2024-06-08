// https://leetcode.cn/problems/combination-sum-iv
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<uint32_t> dp(target + 1);
        dp[0] = 1;
        for (int j = 1; j <= target; ++j) {
            for (int &num : nums) {
                if (j >= num) {
                    dp[j] += dp[j - num];
                }
            }
        }
        return dp[target];
    }
};