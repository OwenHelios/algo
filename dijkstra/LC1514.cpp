// https://leetcode.cn/problems/path-with-maximum-probability/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> g(n);
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<double> dist(n, 0);
        dist[start_node] = 1;
        priority_queue<pair<double, int>> q;
        // same as : priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> q;
        q.emplace(1, start_node);
        while (!q.empty()) {
            auto [d, i] = q.top();
            if (i == end_node) {
                return dist[i];
            }
            q.pop();
            if (dist[i] > d) {
                continue;
            }
            for (auto &[v, w] : g[i]) {
                if (dist[i] * w > dist[v]) {
                    dist[v] = dist[i] * w;
                    q.emplace(dist[v], v);
                }
            }
        }
        return 0;
    }
};