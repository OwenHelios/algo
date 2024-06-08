// https://leetcode.cn/problems/minimum-number-of-coins-for-fruits/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + prices[i];
            int left = i / 2; // leftest index to buy at, making i free: 2 * left + 1 == i
            for (int j = left; j < i; ++j) {
                dp[i + 1] = min(dp[i + 1], dp[j] + prices[j]);
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1); // dp[i] : buying at i
        for (int i = n - 1; i >= 0; --i) {
            int expired = min(2 * i + 1, n - 1);
            dp[i] = dp[expired + 1] + prices[i];
            for (int j = i + 1; j < expired + 1; ++j) {
                dp[i] = min(dp[i], dp[j] + prices[i]);
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        // int memo[n + 1][n + 1];
        // memset(memo, -1, sizeof(memo));
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        function<int(int, int)> dp = [&](int i, int expired) {
            if (i == n) {
                return 0;
            }
            int &ret = memo[i][expired + 1];
            if (ret != -1) {
                return ret;
            }
            ret = dp(i + 1, min(2 * i + 1, n - 1)) + prices[i];
            if (i <= expired) {
                ret = min(ret, dp(i + 1, expired));
            }
            return ret;
        };
        return dp(0, -1);
    }
};