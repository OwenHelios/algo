// https://leetcode.cn/problems/split-array-largest-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        auto check = [&](int limit) {
            int cnt = 1;
            int sum = 0;
            for (int &num : nums) {
                sum += num;
                if (sum > limit) {
                    if (++cnt > k) return false;
                    sum = num;
                }
            }
            return true;
        };
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};