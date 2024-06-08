// https://leetcode.cn/problems/lexicographically-smallest-equivalent-string
#include <bits/stdc++.h>

using namespace std;

class dsu {
public:
    int n;
    vector<int> p;
    dsu(int _n) : n(_n), p(_n) {
        iota(p.begin(), p.end(), 0);
    }

    void join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx > fy) swap(fx, fy);
        p[fy] = fx;
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        dsu t(26);
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            t.join(s1[i] - 'a', s2[i] - 'a');
        }
        for (auto &ch : baseStr) {
            ch = 'a' + t.find(ch - 'a');
        }
        return baseStr;
    }
};