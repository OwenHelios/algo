// https://leetcode.cn/problems/path-with-minimum-effort/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e6));
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, 0, 0);
        vector<pair<int, int>> dt = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [d, i, j] = q.top();
            if (i == m - 1 && j == n - 1) {
                return dist[m - 1][n - 1];
            }
            q.pop();
            if (dist[i][j] < d) {
                continue;
            }
            for (auto &[di, dj] : dt) {
                int ni = i + di, nj = j + dj;
                if (!(ni >= 0 && ni < m && nj >= 0 && nj < n)) continue;
                int nd = max(d, abs(heights[ni][nj] - heights[i][j]));
                if (nd < dist[ni][nj]) {
                    dist[ni][nj] = nd;
                    q.emplace(nd, ni, nj);
                }
            }
        }
        return -1;
    }
};