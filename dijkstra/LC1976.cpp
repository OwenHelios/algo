// https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        for (auto &r : roads) {
            g[r[0]].emplace_back(r[1], r[2]);
            g[r[1]].emplace_back(r[0], r[2]);
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> dp(n);
        dp[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            auto [d, i] = q.top(); // error after pop if referenced &
            if (i == n - 1) {
                return dp[i];
            }
            q.pop();
            if (d > dist[i]) {
                continue;
            }
            for (auto &[v, w] : g[i]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    q.emplace(dist[v], v);
                    dp[v] = dp[i];
                } else if (dist[v] == d + w){
                    dp[v] = (dp[i] + dp[v]) % MOD;
                }
            }
        }
        return -1;
    }
};