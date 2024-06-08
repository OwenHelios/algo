// https://leetcode.cn/problems/coin-change-ii
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int &num : coins) {
            for (int i = num; i <= amount; ++i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[amount];
    }
};