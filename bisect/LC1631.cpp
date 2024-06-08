// https://leetcode.cn/problems/path-with-minimum-effort/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>> dt = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int l = 0, r = 1e6;
        while (l < r) {
            int mid = (l + r) / 2;
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.emplace(0, 0);
            vis[0][0] = true;
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                for (auto &[di, dj] : dt) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (!vis[ni][nj] && abs(heights[ni][nj] - heights[i][j]) <= mid) {
                        q.emplace(ni, nj);
                        vis[ni][nj] = true;
                    }
                }
            }
            if (vis[m - 1][n - 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};