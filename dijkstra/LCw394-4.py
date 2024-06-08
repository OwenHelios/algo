# https://leetcode.cn/problems/find-edges-in-shortest-paths/
from heapq import *
from typing import *
from math import *


class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        g = [[] for _ in range(n+1)]
        for i, (u, v, w) in enumerate(edges):
            g[u].append((v, w, i))
            g[v].append((u, w, i))
        m = len(edges)
        ans = [False] * m
        dist = [inf]*n
        dist[0] = 0
        h = [(0, 0)]
        while h:
            d, i = heappop(h)
            if i == n - 1:
                break
            if dist[i] < d:
                continue
            for u, w, _ in g[i]:
                if dist[u] > dist[i] + w:
                    dist[u] = dist[i] + w
                    heappush(h, (dist[u], u))
        if dist[n - 1] == inf:
            return ans
        q = [n - 1]
        vis = [False] * n
        vis[n - 1] = True
        while q:
            u = q.pop()
            for v, w, i in g[u]:
                if dist[u] != dist[v] + w:
                    continue
                ans[i] = True
                if not vis[v]:
                    vis[v] = True
                    q.append(v)
        return ans


class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        g = [[] for _ in range(n+1)]
        for i, (u, v, w) in enumerate(edges):
            g[u].append((v, w, i))
            g[v].append((u, w, i))
        m = len(edges)
        ans = [False] * m
        dist = [inf]*n
        dist[0] = 0
        last = [[] for _ in range(n)]
        h = [(0, 0)]
        while h:
            d, i = heappop(h)
            if i == n - 1:
                break
            if dist[i] < d:
                continue
            for u, w, j in g[i]:
                if dist[u] > dist[i] + w:
                    dist[u] = dist[i] + w
                    last[u] = [(i, j)]
                    heappush(h, (dist[u], u))
                elif dist[u] == dist[i] + w:
                    last[u].append((i, j))
        q = [n - 1]
        dist = [False] * n
        dist[n - 1] = True
        while q:
            i = q.pop()
            for u, j in last[i]:
                ans[j] = True
                if not dist[u]:
                    dist[u] = True
                    q.append(u)
        return ans
