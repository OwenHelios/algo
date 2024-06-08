// https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<int> items;
        for (int i=1;;++i){
            int pwr = pow(i, x);
            if (pwr > n) break;
            items.push_back(pwr);
        }
        int m = items.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) { // items
            for (int j = 0; j <= n; ++j) { // space (!!! starts with 0)
                if(j < items[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    // picking items[i-1] + not picking
                    dp[i][j] = (1ll * dp[i-1][j-items[i-1]] + dp[i-1][j]) % MOD;
                }
                int xx =1;
            }
        }
        return dp[m][n];
    }
};

int main(){
    return 0;
}