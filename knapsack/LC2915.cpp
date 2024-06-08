// https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        dp[0] = 0;
        int sum = 0;
        for (int &num : nums) {
            sum += num;
            for (int i = min(sum, target); i >= num; --i) {
                if (dp[i - num] != - 1) {
                    dp[i] = max(dp[i], dp[i - num] + 1);
                }
            }
        }
        return dp[target];
    }
};