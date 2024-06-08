#include <bits/stdc++.h>
// https://leetcode.cn/problems/minimum-cost-to-make-array-equalindromic/

using namespace std;
vector<int> pals;
auto init = [] {
for (int base = 1; base <= 10000; base *= 10) {
    for (int i = base; i < base * 10; ++i) {
        // odd len
        int left = i;
        for (int t = i / 10; t > 0; t /= 10) {
            left = left * 10 + t % 10;
        }
        pals.push_back(left);
    }
    if (base == 10000) continue;
    for (int i = base; i < base * 10; ++i) {
        // even len
        int left = i;
        for (int t = i; t > 0; t /= 10) {
            left = left * 10 + t % 10;
        }
        pals.push_back(left);
    }
}
pals.push_back(1'000'000'001);
return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto cost = [&](int pal) {
            long long ret = 0;
            for (auto &num: nums) {
                ret += abs(num - pal);
            }
            return ret;
        };
        int i = lower_bound(pals.begin(), pals.end(), nums[(n - 1) / 2]) - pals.begin();
        if (pals[i] <= nums[n / 2]) {
            return cost(pals[i]);
        }
        return min(cost(pals[i - 1]), cost(pals[i]));
    }
};