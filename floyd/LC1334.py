# https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
from typing import *
from math import *


class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        w = [[inf] * n for _ in range(n)]
        for u, v, weight in edges:
            w[u][v] = weight
            w[v][u] = weight

        f = [[[0] * n for _ in range(n)] for _ in range(n + 1)]
        f[0] = w
        for k in range(n):
            for i in range(n):
                for j in range(n):
                        f[k + 1][i][j] = min(f[k][i][j], f[k][i][k] + f[k][k][j])

        ans = -1
        mn = n
        for i in range(n):
            cnt = 0
            for j in range(n):
                if j != i and f[n][i][j] <= distanceThreshold:
                    cnt += 1
            if cnt <= mn:
                mn = cnt
                ans = i
        return ans