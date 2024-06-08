// https://leetcode.cn/problems/restore-the-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        if (s[0] == '0') return 0;
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            long long cur = s[i] - '0';
            dp[i + 1] = cur && cur <= k ? dp[i] : 0;
            long long base = 1;
            for (int j = i - 1; j >= 0; --j) {
                base *= 10;
                cur = (s[j] - '0') * base + cur;
                if (cur > k || base > k) break;
                if (s[j] != '0') {
                    dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
                }
            }
        }
        return dp[n];
    }
};
