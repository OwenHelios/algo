// https://leetcode.cn/problems/maximum-strength-of-k-disjoint-subarrays
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sign(int i) {
        return i % 2 ? 1 : -1;
    }

    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i < k; ++i) {
            int w = sign(i + 1) * (k - i);
            long long mx = LLONG_MIN;
            for (int j = i; j <= n - (k - i); ++j) { // n - j - 1 >= k - i - 1
                // dp[i + 1][j + 1]: split nums[0] ~ nums[j] into i + 1 groups (j >= i)
                dp[i + 1][j + 1] = j > i ? dp[i + 1][j] : LLONG_MIN; // skip nums[j]
                mx = max(mx, dp[i][j] - w * pref[j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], w * pref[j + 1] + mx);
                // for (int l = i; l <= j; ++l) {
                //     dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][l] + w * (pref[j + 1] - pref[l]));
                // }
            }
            int z = 1;
        }
        return dp[k][n];
    }
};

class Solution {
public:
    long long sign(int i) {
        return i % 2 ? 1 : -1;
    }

    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp1(k + 1, LLONG_MIN); // dp1[i] : ith part includes last num
        vector<long long> dp2(k + 1, LLONG_MIN); // dp2[i] : ith part may or may not include last num
        dp1[0] = 0;
        dp2[0] = 0;
        for (int &num : nums) {
            for (int i = k; i > 0; --i) {
                dp1[i] = max(dp1[i], dp2[i - 1]);
                !!!
                if (dp1[i] != LLONG_MIN) {
                    dp1[i] += sign(i) * (k - i + 1) * num;
                }
                dp2[i] = max(dp1[i], dp2[i]);
            }
        }
        return dp2[k];
    }
};