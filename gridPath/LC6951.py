# https://leetcode.cn/problems/find-the-safest-path-in-a-grid
from typing import *


class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        # dist[i][j]: distance of (i, j) to the closest 1
        dist = [[-1]*n for _ in range(n)]
        q = []
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i, j))
        depth = 1
        groups = []
        while q:
            groups.append(q)
            tmp, q = q, []
            for i, j in tmp:
                for x, y in (i+1, j), (i, j+1), (i-1, j), (i, j-1):
                    if 0 <= x < n and 0 <= y < n and dist[x][y] == -1:
                        dist[x][y] = depth
                        q.append((x, y))
            depth += 1

        uf = DSU(n*n)
        mx = len(groups) - 1  # max distance from 1 out of all cells
        for k in range(mx, -1, -1):
            for i, j in groups[k]:
                for x, y in (i+1, j), (i, j+1), (i-1, j), (i, j-1):
                    if 0 <= x < n and 0 <= y < n and dist[x][y] >= dist[i][j]:
                        uf.union(x*n+y, i*n+j)
            if uf.find(0) == uf.find(n*n-1):
                return k


class DSU:
    def __init__(self, n) -> None:
        self.p = list(range(n))

    def union(self, x, y):
        fx = self.find(x)
        fy = self.find(y)
        if fx == fy:
            return
        self.p[fx] = fy

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
