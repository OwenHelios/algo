// https://leetcode.cn/problems/course-schedule-ii
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int UNVISITED = 0;
    const int VISITING = 1;
    const int VISITED = 2;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto &p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        vector<int> vis(numCourses);
        vector<int> ans;
        function<bool(int)> dfs = [&](int i) {
            vis[i] = VISITING;
            for (auto &u : g[i]) {
                if (vis[u] == VISITING) {
                    return false;
                }
                if (vis[u] == UNVISITED && !dfs(u)) {
                    return false;
                }
            }
            // append outwards
            // a->b->c  dfs(b), dfs(a)  => [c, b, a]
            ans.push_back(i);
            vis[i] = VISITED;
            return true;
        };
        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] == UNVISITED && !dfs(i)) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses);
        for (auto &p : prerequisites) {
            // p[1] -> p[0]
            g[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int &v : g[u]) {
                indeg[v]--;
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }
        return ans;
    }
};