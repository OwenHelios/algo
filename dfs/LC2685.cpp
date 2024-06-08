#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int e, v;
        int ans = 0;
        function<void(int)> dfs = [&](int i) {
            vis[i] = true;
            v++;
            e += g[i].size();
            for (int j: g[i]) {
                if (!vis[j]) dfs(j);
            }
        };
        for (int i=0;i<n;++i) {
            if (vis[i]) continue;
            e = 0;
            v = 0;
            dfs(i);
            ans += (e==v*(v-1));
        }
        return ans;
    }
};