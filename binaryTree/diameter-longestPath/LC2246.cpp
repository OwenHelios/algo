// https://leetcode.cn/problems/longest-path-with-different-adjacent-characters/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        int ans = 0;
        function<int(int)> dfs = [&](int i){
            int mx = 0;
            for (int &j : children[i]) {
                int cur = dfs(j) + 1;
                if (s[i] == s[j]) continue;
                ans = max(ans, mx + cur);
                mx = max(mx, cur);
            }
            return mx;
        };
        dfs(0);
        return ans + 1;
    }
};

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        int ans = 0;
        function<int(int)> dfs = [&](int i){
            int mx1 = 0;
            int mx2 = 0;
            for (int &j : children[i]) {
                int cur = dfs(j) + 1;
                if (s[i] == s[j]) continue;
                if (cur > mx1) {
                    mx2 = mx1;
                    mx1 = cur;
                } else if (cur > mx2) {
                    mx2 = cur;
                }
            }
            ans = max(ans, mx1 + mx2);
            return mx1;
        };
        dfs(0);
        return ans + 1;
    }
};