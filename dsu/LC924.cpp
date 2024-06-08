// https://leetcode.cn/problems/minimize-malware-spread
#include <bits/stdc++.h>

using namespace std;

class dsu {
public:
    vector<int> p;
    vector<int> sz;
    dsu(int _n) : p(_n), sz(_n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    void join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            p[fx] = fy;
            sz[fy] += sz[fx];
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        dsu f(n);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j]) {
                    f.join(i, j);
                }
            }
        }
        int mx = 0;
        int ans = n;
        vector<int> cnt(n);
        for (int &i : initial) {
            int j = f.find(i);
            int cur = f.sz[j];
            ans = min(ans, i);
            cnt[j]++;
        }
        for (int &i : initial) {
            int j = f.find(i);
            int cur = f.sz[j];
            if (cnt[j] != 1) continue;
            if (cur > mx) {
                ans = i;
                mx = cur;
            } else if (cur == mx && i < ans) {
                ans = i;
            }
        }
        return ans;
    }
};