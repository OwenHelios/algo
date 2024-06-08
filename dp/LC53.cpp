#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int ans = dp;
        int n = nums.size();
        for (int i=1;i<n;++i) {
            // max valid subarray sum ending with nums[i]
            // include nums[i-1] vs not
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
    }
};