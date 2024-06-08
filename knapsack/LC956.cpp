// https://leetcode.cn/problems/tallest-billboard/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int k = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(k + 1); // dp[i] = max(left + right) when abs(left - right) == i
        for (int &r : rods) {
            auto tmp = dp;
            for (int i = 0; i <= k; ++i) {
                if (i && !tmp[i]) continue; // invalid
                // add to taller side
                dp[i + r] = max(dp[i + r], tmp[i] + r);
                // add to shorter side
                dp[abs(i - r)] = max(dp[abs(i - r)], tmp[i] + r);
            }
        }
        return dp[0] / 2;
    }
};


class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp.emplace(0, 0);
        for (int &num : rods) {
            auto tmp = dp; // !! copy
            for (auto &[sum, height] : tmp) {
                dp[sum + num] = max(dp[sum + num], height + num);
                dp[sum - num] = max(dp[sum - num], height);
            }
        }
        return dp[0];
    }
};