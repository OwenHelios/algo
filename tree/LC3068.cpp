// https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/description/
#include <bits/stdc++.h>
// bw125-4
using namespace std;
#define i64 long long

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        auto diff = nums;
        for (int &num : diff) {
            num = (num ^ k) - num; // !!! operator precedence: ^ is weaker than -
        }
        sort(diff.begin(), diff.end(), greater<int>());
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums[i];
            if (i % 2 == 0 && i + 1 < n && diff[i] + diff[i + 1] > 0) {
                ans += diff[i] + diff[i + 1];
            }
        }
        return ans;
    }
};