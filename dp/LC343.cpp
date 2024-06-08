// https://leetcode.cn/problems/integer-break/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            if (i < n) {
                dp[i] = i;
            }
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], dp[i - j] * j);
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int pow(int x, int y) {
        long long cur = x;
        int ret = 1;
        while (y) {
            if (y & 1) {
                ret *= cur;
            }
            y >>= 1;
            cur *= cur;
        }
        return ret;
    }

    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int m = n % 3;
        int d = n / 3;
        switch (m) {
            case 0:
                return pow(3, d);
            case 1:
                return pow(3, d - 1) * 4;
            case 2:
                return pow(3, d) * 2;
            default:
                return -1;
        }
    }
};