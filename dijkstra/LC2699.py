# https://leetcode.cn/problems/modify-graph-edge-weights/
from collections import *
from copy import copy, deepcopy
from heapq import *
from typing import *
from math import *


class Solution:
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        g = [[] for _ in range(n)]
        for i, (u, v, w) in enumerate(edges):
            g[u].append((v, i))
            g[v].append((u, i))
        dist = [[inf, inf] for _ in range(n)]
        dist[source][0] = 0
        dist[source][1] = 0

        def dijkstra(k):
            vis = [False]*(n)
            while True:
                j = -1
                for i in range(n):
                    if not vis[i] and (j == -1 or dist[i][k] < dist[j][k]):
                        j = i
                if j == destination:
                    return
                vis[j] = True
                for u, eid in g[j]:
                    w = edges[eid][2]
                    if w == -1:
                        w = 1
                        if k == 1:
                            nw = target - \
                                dist[destination][0] - dist[j][1] + dist[u][0]
                            edges[eid][2] = w = nw if nw > 0 else w
                    dist[u][k] = min(dist[u][k], dist[j][k] + w)
        dijkstra(0)
        if dist[destination][0] > target:
            return []
        dijkstra(1)
        if dist[destination][1] < target:
            return []
        for e in edges:
            if e[2] == -1:
                e[2] = 1
        return edges


sol = Solution()
res = sol.modifiedGraphEdges(
    5, [[4, 1, -1], [2, 0, -1], [0, 3, -1], [4, 3, -1]], 0, 1, 5)
print(res)
