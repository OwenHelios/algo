// https://leetcode.cn/problems/partition-equal-subset-sum
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int k = sum / 2;
        vector<int> dp(k + 1);
        dp[0] = 1;
        for (int &num : nums) {
            for (int i = k; i >= num; --i) {
                dp[i] |= dp[i - num];
            }
        }
        return dp[k];
    }
};