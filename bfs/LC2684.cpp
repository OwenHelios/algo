// https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vis(m, 0); // vis[i] == j : (i, j) right most visited in row i
        vector<int> q(m);
        iota(q.begin(), q.end(), 0); // 0 ~ m-1
        for (int j = 0; j < n - 1; ++j) {
            vector<int> tmp;
            for (int i : q) {
                for (int ni = max(i - 1, 0); ni < min(i + 2, m); ++ni) {
                    if (vis[ni] != j + 1 && grid[ni][j + 1] > grid[i][j]) {
                        tmp.push_back(ni);
                        vis[ni] = j + 1;
                    }
                }
            }
            if (tmp.empty()) {
                return j;
            }
            q = move(tmp);
        }
        return n - 1;
    }
};