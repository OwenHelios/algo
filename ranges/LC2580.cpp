// https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges
#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int cnt = 0;
        sort(ranges.begin(), ranges.end());
        int last = -1;
        int ans = 1;
        for (auto &r : ranges) {
            if (r[0] > last) {
                cnt++;
                ans = 1ll * ans * 2 % MOD;
            }
            last = max(last, r[1]);
        }
        // ans = pow(2, cnt);
        return ans;
    }
};