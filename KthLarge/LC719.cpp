// https://leetcode.cn/problems/find-k-th-smallest-pair-distance/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums.front();
        int n = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            int i = 0;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                while (nums[j] - nums[i] > mid) {
                    i++;
                }
                cnt += j - i;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};