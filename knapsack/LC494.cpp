// https://leetcode.cn/problems/target-sum/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0) return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        int acc = 0;
        for (int num : nums) {
            num *= 2;
            acc += num;
            for (int i = min(acc, target); i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};