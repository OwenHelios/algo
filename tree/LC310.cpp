// https://leetcode.cn/problems/minimum-height-trees
#include <bits/stdc++.h>

using namespace std;

// for any tree
// take random node 0, x is the furthest node from 0, y is the furthest node from x
// dist(x, y) is the max distance between any 2 nodes
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1);
        function<pair<int, int>(int)> dfs = [&](int i) {
            int mx = -1;
            int j = i;
            for (int &u : g[i]) {
                if (u != parent[i]) {
                    parent[u] = i;
                    auto [v, d] = dfs(u);
                    if (d > mx) {
                        j = v;
                        mx = d;
                    }
                }
            }
            return make_pair(j, mx + 1);
        };
        auto [x, _] = dfs(0);
        parent[x] = -1;
        auto [y, d] = dfs(x);
        int h = d / 2;
        while (h--) {
            y = parent[y];
        }
        if (d % 2) {
            return {y, parent[y]};
        } else {
            return {y};
        }
    }
};