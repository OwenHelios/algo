// https://leetcode.cn/problems/largest-divisible-subset/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n);
        vector<int> ans;
        int mx_cnt = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > mx_cnt) {
                mx_cnt = dp[i];
                last = nums[i];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == mx_cnt && last % nums[i] == 0) {
                ans.push_back(nums[i]);
                mx_cnt--;
                last = nums[i];
            }
            if (!mx_cnt) break;
        }
        return ans;
    }
};

/*
OVERTIME:
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int> vis;
        sort(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        int mx_cnt = 0;
        for (int &num : nums) {
            if (vis.find(num) != vis.end()) continue;
            long long cur = num;
            int valid = num;
            vector<int> sub;
            while (cur <= mx) {
                if (s.find(cur) != s.end()) {
                    sub.push_back(cur);
                    vis.insert(cur);
                    valid = cur;
                }
                cur += valid;
            }
            if (sub.size() > mx_cnt) {
                ans = sub;
                mx_cnt = sub.size();
            }
        }
        return ans;
    }
};

*/