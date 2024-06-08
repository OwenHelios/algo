# https://leetcode.cn/problems/minimum-cost-to-convert-string-i/
from typing import *
from math import *


class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        def idx(ch):
            return ord(ch) - ord('a')
        w = [[inf] * 26 for _ in range(26)]
        m = len(original)
        for i in range(m):
            x = original[i]
            y = changed[i]
            w[x][y] = min(w[x][y], cost[i])
        
        f = [[[0] * 26 for _ in range(26)] for _ in range(27)]
        f[0] = w
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    f[k + 1][i][j] = min(f[k][i][j], f[k][i][k] + f[k][k][j])
        
        ans = 0
        for s, t in zip(source, target):
            if s != t:
                ans += f[27][idx(s)][idx(t)]
        return -1 if ans == inf else ans