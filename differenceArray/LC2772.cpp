// https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        int dx = 0; // nums[i] should become nums[i] + dx
        vector<int> delta(n + 1); // dx should become dx + delta[i]
        for (int i = 0; i < n; ++i) {
            dx += delta[i];
            int x = nums[i] + dx;
            if (x < 0 || x > 0 && i + k > n) {
                return false;
            }
            if (x) {
                dx -= x;
                delta[i + k] += x;
            }
        }
        return true;
    }
};