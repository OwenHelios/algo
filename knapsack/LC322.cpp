// https://leetcode.cn/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int &num : coins) {
            for (int i = num; i <= amount; ++i) {
                if (dp[i - num] != amount + 1) {
                    dp[i] = min(dp[i], dp[i - num] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 10001));
        dp[0][0] = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<amount+1;j++) {
                if (j<coins[i]) {
                    dp[i+1][j] = dp[i][j];
                } else {
                    dp[i+1][j] = min(dp[i+1][j-coins[i]]+1, dp[i][j]);
                }
            }
        }
        return dp[n][amount] == 10001 ? -1 : dp[n][amount];
    }
};

int main(){
    return 0;
}