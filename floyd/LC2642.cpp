// https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/
#include <bits/stdc++.h>

using namespace std;

class Graph {
int MAXD = 1e8 + 1;
vector<vector<int>> dist;
int n;
public:
    Graph(int _n, vector<vector<int>>& edges) : dist(_n, vector<int>(_n, MAXD)), n(_n){
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = min(dist[u][v], w);
        }
        for (int k = 0; k < n; ++k) {
            dist[k][k] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (w > dist[u][v]) return;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return dist[node1][node2] == MAXD ? -1 : dist[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */