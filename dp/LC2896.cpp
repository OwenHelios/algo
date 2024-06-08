#include <bits/stdc++.h>
// https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> diff;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) diff.push_back(i);
        }
        int m = diff.size();
        if (!m) return 0;
        if (m % 2) return -1;
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            if (i == 1) {
                dp[i] = x;
                continue;
            }
            dp[i] = min(dp[i - 1] + x, dp[i - 2] + 2 * (diff[i - 1] - diff[i - 2]));
        }
        return dp[m] / 2;
    }
};