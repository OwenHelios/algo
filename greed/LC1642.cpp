// https://leetcode.cn/problems/furthest-building-you-can-reach/
#include <bits/stdc++.h>

using namespace std;
// 反悔贪心
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int n = heights.size();
        for (int i = 1; i < n; ++i) {
            if (heights[i] <= heights[i - 1]) continue;
            int diff = heights[i] - heights[i - 1];
            bricks -= diff;
            q.push(diff);
            if (bricks < 0) {
                bricks += q.top();
                q.pop();
                ladders--;
            }
            if (ladders < 0) {
                return i - 1;
            }
        }
        return n - 1;
    }
};