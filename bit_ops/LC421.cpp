// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        int mx = *max_element(nums.begin(), nums.end());
        // __builtin_clz(x): the number of leading 0-bits in x. [x != 0]
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;
        unordered_set<int> seen;
        for (int k = high_bit; k >= 0; --k) {
            mask |= (1 << k);
            int cur = ans | (1 << k);
            seen.clear();
            for (int num: nums){
                num &= mask;
                if (seen.find(num ^ cur) != seen.end()) { // ∃ a, b ∈ nums: a ^ b == cur
                    ans = cur;
                    break;
                }
                seen.insert(num);
            }
        }
        return ans;
    }
};