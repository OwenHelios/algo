// https://leetcode.cn/problems/pizza-with-3n-slices/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size(); // items
        int k = n / 3; // space
        vector<vector<int>> dp1(k + 1, vector<int>(n + 1)); // slices[0] allowed
        vector<vector<int>> dp2(k + 1, vector<int>(n + 1)); // slices[0] not allowed
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i == 0) {
                    dp1[j][i + 1] = slices[i];
                } else {
                    dp1[j][i + 1] = max(dp1[j - 1][i - 1] + slices[i], dp1[j][i]);
                    dp2[j][i + 1] = max(dp2[j - 1][i - 1] + slices[i], dp2[j][i]);
                }
            }
        }
        return max(dp1[k][n - 1], dp2[k][n]);
    }
};

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size(); // items
        int k = n / 3; // space
        vector<array<int, 4>> dp(k + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                auto &[pre1, cur1, pre2, cur2] = dp[j];
                if (i == 0) {
                    cur1 = slices[0];
                } else {
                    pre1 = cur1;
                    cur1 = max(cur1, dp[j - 1][0] + slices[i]);
                    pre2 = cur2;
                    cur2 = max(cur2, dp[j - 1][2] + slices[i]);
                }
            }
        }
        return max(dp[k][0], dp[k][3]);
    }
};