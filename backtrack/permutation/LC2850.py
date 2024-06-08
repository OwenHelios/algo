# https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid
from typing import *
from itertools import permutations


class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        mv_from = []
        mv_to = []
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val > 1:
                    mv_from.extend([(i, j)]*(val - 1))
                elif val == 0:
                    mv_to.append((i, j))
        ans = 99
        for p_from in permutations(mv_from):
            cur = 0
            for (x1, y1), (x2, y2) in zip(p_from, mv_to):
                cur += abs(x1 - x2) + abs(y1 - y2)
            ans = min(ans, cur)
        return ans
