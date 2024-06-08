// https://leetcode.cn/problems/minimum-cost-of-a-path-with-special-roads/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        pair<int, int> t = make_pair(target[0], target[1]);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, start[0], start[1]);
        map<pair<int, int>, int> dist;
        dist.emplace(make_pair(start[0], start[1]), 0);
        dist.emplace(t, INT_MAX);
        while (!q.empty()) {
            auto [d, x, y] = q.top();
            if (x == target[0] && y == target[1]) {
                return d;
            }
            q.pop();
            int dt = d + abs(x - target[0]) + abs(y - target[1]);
            if (dt < dist[t]) {
                dist[t] = dt;
                q.emplace(dt, target[0], target[1]);
            }
            for (auto &r : specialRoads) {
                auto from = make_pair(r[0], r[1]);
                auto to = make_pair(r[2], r[3]);
                if (!dist.count(to) || d + abs(x - r[0]) + abs(y - r[1]) + r[4] < dist[to]) {
                    dist[to] = d + abs(x - r[0]) + abs(y - r[1]) + r[4];
                    q.emplace(dist[to], r[2], r[3]);
                }
            }
        }
        return -1;
    }
};