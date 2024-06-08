// https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> g;
    int n;
public:
    Graph(int _n, vector<vector<int>>& edges) 
        : g(_n, vector<pair<int, int>>()), n(_n)
    {
        for (auto &e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> done(n, false);
        dist[node1] = 0;
        while (true) {
            int j = n;
            for (int i = 0; i < n; ++i) {
                if (!done[i] && dist[i] < dist[j]) {
                    j = i;
                }
            }
            if (j == n) break;
            done[j] = true;
            for (auto &[v, w] : g[j]) {
                dist[v] = min(dist[v], dist[j] + w);
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> g;
    int n;
public:
    Graph(int _n, vector<vector<int>>& edges) 
        : g(_n, vector<pair<int, int>>()), n(_n)
    {
        for (auto &e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n + 1, INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, node1);
        while (!q.empty()) {
            auto [d, i] = q.top();
            q.pop();
            if (dist[i] < d) {
                continue;
            }
            for (auto &[v, w] : g[i]) {
                if (dist[i] + w < dist[v]) {
                    dist[v] = dist[i] + w;
                    q.emplace(dist[v], v);
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */