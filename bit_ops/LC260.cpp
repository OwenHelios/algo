// https://leetcode.cn/problems/single-number-iii/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0; // answer
        long long x = 0;
        for (auto &num: nums) {
            x ^= num;
        }
        // x == a ^ b
        // a, b differs on at least one bit (x != 0)
        int low_bit = x & -x; // -x might overflow
        for (auto &num: nums) {
            if (num & low_bit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};