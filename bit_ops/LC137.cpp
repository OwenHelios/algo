// https://leetcode.cn/problems/single-number-ii/
#include <bits/stdc++.h>

using namespace std;
// Solution 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (auto &num: nums) {
                cnt += num >> i & 1;
            }
            ans |= cnt % 3 << i;
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x: nums) {
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }
        return b;
    }
};