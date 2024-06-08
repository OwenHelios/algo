#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> g(n);
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        g[0].push_back(-1);
        long long sum = 0;
        function<long long(int, int)> dfs = [&](int i, int p) {
            sum += values[i];
            long long ret1 = values[i];
            if (g[i].size() == 1) return ret1;
            long long ret2 = 0;
            for (int &u: g[i]) {
                if (u == p) continue;
                ret2 += dfs(u, i);
            }
            return min(ret1, ret2);
        };
        long long cost = dfs(0, -1);
        return sum - cost;
    }
};