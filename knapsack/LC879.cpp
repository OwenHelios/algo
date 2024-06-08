// https://leetcode.cn/problems/profitable-schemes/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        int m = group.size();
        for (int i = 0; i < m; ++i) {
            for (int j = n; j >= group[i]; --j) {
                for (int p = 0; p <= minProfit; ++p) {
                    dp[j][p] = (1ll * dp[j][p] + dp[j - group[i]][max(p - profit[i], 0)]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};

class Solution {
public:
    int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mxp = max(accumulate(profit.begin(), profit.end(), 0), minProfit);
        vector<vector<int>> dp(n + 1, vector<int>(mxp + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        int m = group.size();
        for (int i = 0; i < m; ++i) {
            for (int j = n; j >= group[i]; --j) {
                for (int p = profit[i]; p <= mxp; ++p) {
                    dp[j][p] = (1ll * dp[j][p] + dp[j - group[i]][p - profit[i]]) % MOD;
                }
            }
        }
        return accumulate(dp[n].begin() + minProfit, dp[n].end(), 0ll) % MOD;
    }
};