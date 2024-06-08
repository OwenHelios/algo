// https://leetcode.cn/problems/number-of-ways-to-separate-numbers/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    int numberOfCombinations(string num) {
        if (num[0] == '0') return 0;
        int n = num.size();
        int dp[n + 1][n + 1];
        dp[0][0] = 1;
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                int left = i - 1 - j + i;
                if (num[i] == '0' || left >= 0 && num[left] == '0') continue;
                if (left >= 0 && num.substr(left, j - i + 1) <= num.substr(i, j - i + 1)) {
                    dp[i + 1][j + 1] += dp[left + 1][i];
                }
                for (int k = max(left + 1, 0); k < i; ++k) {
                    dp[i + 1][j + 1] += dp[k + 1][i];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i + 1][n]);
        }
        return ans;
    }
};