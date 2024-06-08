// https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> ans(n);
        vector<int> vis(n, -1);
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int &v : g[u]) {
                    if (vis[v] != i) {
                        vis[v] = i;
                        q.push(v);
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j] == i) {
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
        }
        vector<vector<int>> ans(n);
        vector<int> vis(n, -1);
        int root;
        function<void(int)> dfs = [&](int u) {
            vis[u] = root;
            for (int &v : g[u]) {
                if (vis[v] != root) {
                    ans[v].push_back(root);
                    dfs(v);
                }
            }
        };
        for (root = 0; root < n; ++root) {
            dfs(root);
        }
        return ans;
    }
};