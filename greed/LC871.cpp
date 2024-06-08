// https://leetcode.cn/problems/minimum-number-of-refueling-stops/
#include <bits/stdc++.h>

using namespace std;
// 反悔贪心
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cur = startFuel;
        priority_queue<int> q;
        int ans = 0;
        int n = stations.size();
        for (int i = 0; i <= n; ++i) {
            int next = i == n ? target : stations[i][0];
            while (!q.empty() && cur < next) {
                cur += q.top();
                q.pop();
                ans++;
            }
            if (cur < next) {
                return -1; 
            }
            if (i != n) {
                q.push(stations[i][1]);
            }
        }
        return ans;
    }
};