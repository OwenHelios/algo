// https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-i
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0; i < n; ++i) {
            left[i] = i ? min(left[i - 1], nums[i]) : nums[i];
            int j = n - i - 1;
            right[j] = j == n - 1 ? nums[j] : min(right[j + 1], nums[j]);
        }
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; ++i) {
            if (left[i] < nums[i] && right[i] < nums[i]) {
                ans = min(ans, left[i] + nums[i] + right[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};