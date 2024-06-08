// https://leetcode.cn/problems/broken-board-dominoes/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        int N = n * m;
        vector<vector<int>> g(N);
        vector<bool> holes(N);
        for (auto &b : broken) {
            holes[b[0] * m + b[1]] = true;
        }
        int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = i * m + j;
                if (holes[u]) continue;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + delta[k][0];
                    int nj = j + delta[k][1];
                    int v = ni * m + nj;
                    if (ni < 0 || ni == n || nj < 0 || nj == m || holes[v]) continue;
                    g[u].push_back(v);
                }
            }
        }
        vector<int> match(N, -1);
        vector<int> vis(N, -1);
        int ans = 0;
        for (int root = 0; root < N; ++root) {
            if (match[root] != -1) continue;
            function<bool(int)> dfs = [&](int u) {
                vis[u] = root;
                for (int &v : g[u]) {
                    int mv = match[v];
                    if (mv == -1 || vis[mv] != root && dfs(mv)) {
                        match[u] = v;
                        match[v] = u;
                        return true;
                    }
                }
                return false;
            };
            if (dfs(root)) {
                ans++;
            }
        }
        return ans;
    }
};