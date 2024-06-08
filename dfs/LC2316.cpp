// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        for (auto edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        function<int(int)> dfs = [&](int node) {
            int cnt = 0;
            for (int nei: g[node]) {
                if (vis[nei]) continue;
                vis[nei] = true;
                cnt += dfs(nei);
            }
            return cnt;
        };
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int cnt = dfs(i);
            ans += 1ll * cnt * (n - cnt);
        }
        return ans / 2;
    }
};