// https://leetcode.cn/problems/is-graph-bipartite
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        function<bool(int, int, int)> dfs = [&](int i, int c, int p) {
            if (color[i]) return color[i] == c;
            color[i] = c;
            for (int &j : graph[i]) {
                if (j != p && !dfs(j, -c, i)) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (!color[i] && !dfs(i, 1, -1)) {
                return false;
            }
        }
        return true;
    }
};