// https://leetcode.cn/problems/longest-strictly-increasing-or-strictly-decreasing-subarray
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int compare(int a, int b) {
        return a > b ? 1 : (a < b ? -1 : 0);
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int ans = 1;
        while (i < n) {
            int sign = compare(nums[i], nums[i - 1]);
            int j = i - 1;
            while (i + 1 < n && compare(nums[i + 1], nums[i]) == sign) {
                i++;
            }
            if (sign) {
                ans = max(ans, i - j + 1);
            }
            i++;
        }
        return ans;
    }
};

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int ans = 1;
        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            bool up = nums[i] > nums[i - 1];
            int j = i - 1;
            while (i + 1 < n && nums[i + 1] != nums[i] && nums[i + 1] > nums[i] == up) {
                i++;
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int sign = 1;
        int n = nums.size();
        int cur = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int val = (nums[i] - nums[i - 1]) * sign;
            if (!val) {
                cur = 1;
            } else if (val < 0) {
                sign = -sign;
                cur = 2;
            } else {
                cur++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};