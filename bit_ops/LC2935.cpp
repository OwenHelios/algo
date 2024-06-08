// https://leetcode.cn/problems/maximum-strong-pair-xor-ii/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int mask = 0;
        int mx = *max_element(nums.begin(), nums.end());
        // __builtin_clz(x): the number of leading 0-bits in x. [x != 0]
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;
        unordered_map<int, int> seen;
        for (int k = high_bit; k >= 0; --k) {
            mask |= (1 << k);
            int cur = ans | (1 << k);
            seen.clear();
            for (int num: nums){
                int old = num;
                num &= mask;
                int tar = num ^ cur;
                if (seen.find(tar) != seen.end() && 2 * seen[tar] >= old) { // ∃ a, b ∈ nums: a ^ b == cur
                    ans = cur;
                    break;
                }
                seen[num] = old;
            }
        }
        return ans;
    }
};