// https://leetcode.cn/problems/minimize-malware-spread-ii
#include <bits/stdc++.h>

using namespace std;

class dsu {
public:
    vector<int> p;
    vector<int> sz;
    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        p[fx] = fy;
        sz[fy] += sz[fx];
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<bool> vis(n);
        int ans = -1;
        int mn = n;
        sort(initial.begin(), initial.end());
        for (auto &num : initial) {
            dsu f(n);
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (i == num || j == num || !graph[i][j]) continue;
                    f.join(i, j);
                }
            }
            fill(vis.begin(), vis.end(), false);
            int cur = 0;
            for (int &other : initial) {
                if (other == num) continue;
                int fo = f.find(other);
                if (!vis[fo]) {
                    cur += f.sz[fo];
                    vis[fo] = true;
                }
            }
            if (cur < mn) {
                mn = cur;
                ans = num;
            }
        }
        return ans;
    }
};