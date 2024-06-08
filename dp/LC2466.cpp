// https://leetcode.cn/problems/count-ways-to-build-good-strings/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD = 1e9 + 7;
        vector<long long> dp(high + 1, 0);
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] += dp[i - zero];
            }
            if (i >= one) {
                dp[i] += dp[i - one];
            }
            dp[i] %= MOD;
            if (i >= low) {
                ans = (ans + dp[i]) % MOD;
            }
        }
        return ans;
    }
};