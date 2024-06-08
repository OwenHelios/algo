// https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n - 1);
        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        function<int(int, int)> dfs = [&](int i, int p) {
            !!!
        };
        dfs(1, 0);
        return ans;
    }
};