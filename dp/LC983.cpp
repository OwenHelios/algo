// https://leetcode.cn/problems/minimum-cost-for-tickets/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.size();
        vector<int> dp(m);
        for (int i = m - 1; i >= 0; --i) {
            int j = i + 1;
            dp[i] = costs[0] + (j == m ? 0 : dp[j]);
            while (j < m && days[j] < days[i] + 7) {
                j++;
            }
            dp[i] = min(dp[i], costs[1] + (j == m ? 0 : dp[j]));
            while (j < m && days[j] < days[i] + 30) {
                j++;
            }
            dp[i] = min(dp[i], costs[2] + (j == m ? 0 : dp[j]));
        }
        return dp[0];
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.size();
        map<pair<int, int>, int> memo;
        function<int(int, int)> dp = [&](int i, int expired) {
            if (i == m) return 0;
            int &ret = memo[make_pair(i, expired)];
            if (ret != 0) {
                return ret;
            }
            if (expired >= days[i]) {
                return dp(i + 1, expired);
            }
            ret = dp(i + 1, days[i]) + costs[0];
            ret = min(ret, dp(i + 1, days[i] + 6) + costs[1]);
            ret = min(ret, dp(i + 1, days[i] + 29) + costs[2]);
            return ret;
        };
        return dp(0, 0);
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        vector<bool> need(366, false);
        int mx = 0;
        for (int &d : days) {
            need[d] = true;
            mx = max(mx, d);
        }
        for (int i = 1; i <= mx; ++i) {
            if (!need[i]) {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = dp[i - 1] + costs[0];
            dp[i] = min(dp[i], (i >= 7 ? dp[i - 7] : 0) + costs[1]);
            dp[i] = min(dp[i], (i >= 30 ? dp[i - 30] : 0) + costs[2]);
        }
        return dp[mx];
    }
};