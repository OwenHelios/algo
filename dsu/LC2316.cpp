// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
#include <bits/stdc++.h>

using namespace std;
class dsu {
public:
    int n;
    vector<int> p;
    vector<int> sz;

    dsu(int _n): n(_n) {
        p.resize(n);
        sz.resize(n);
        fill(sz.begin(), sz.end(), 1);
        iota(p.begin(), p.end(), 0);
    }

    bool join(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa == fb) return false;
        p[fa] = fb;
        sz[fb] += sz[fa];
        return true;
    }

    int find(int a) {
        if (p[a] != a) {
            p[a] = find(p[a]);
        }
        return p[a];
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        dsu uf(n);
        for (auto edge: edges) {
            uf.join(edge[0], edge[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += n - uf.sz[uf.find(i)];
        }
        return ans / 2;
    }
};