from collections import *
from copy import copy, deepcopy
from heapq import *
from typing import *

# https://leetcode.cn/problems/network-delay-time


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dist = [float('inf')]*(n+1)
        dist[k] = 0
        g = [[] for _ in range(n+1)]
        for u, v, w in times:
            g[u].append((v, w))
        vis = [False]*(n+1)

        while True:
            j = -1
            mn = float('inf')
            for i in range(1, n+1):
                if not vis[i] and dist[i] < mn:
                    mn = dist[i]
                    j = i
            if j == -1:
                break
            vis[j] = True
            for v, w in g[j]:
                dist[v] = min(dist[v], dist[j] + w)
        ans = max(dist)
        return -1 if ans == float('inf') else ans
