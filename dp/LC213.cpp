// https://leetcode.cn/problems/house-robber-ii/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int cur1 = 0, pre1 = 0; // nums[0] allowed
        int cur2 = 0, pre2 = 0; // nums[0] not allowed
        int tmp = -1;
        for (int &num : nums) {
            if (tmp != -1) {
                tmp = cur2;
                cur2 = max(pre2 + num, cur2);
                pre2 = tmp;
            }
            tmp = cur1;
            cur1 = max(pre1 + num, cur1);
            pre1 = tmp;
        }
        return max(pre1, cur2);
    }
};