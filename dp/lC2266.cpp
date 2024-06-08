// https://leetcode.cn/problems/count-number-of-texts/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        int MOD = 1e9 + 7;
        vector<int> opt(10, 3);
        opt[7] = 4;
        opt[9] = 4;
        int n = pressedKeys.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            int d = pressedKeys[i] - '0';
            for (int j = i; j < min(i + opt[d], n) && pressedKeys[j] == pressedKeys[i]; ++j) {
                dp[i] += dp[j + 1];
                dp[i] %= MOD;
            }
        }
        return dp[0];
    }
};