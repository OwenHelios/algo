# https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii/
from typing import *
from bisect import *

class Fenwick:
    __slots__ = ['tree']

    def __init__(self, n) -> None:
        self.tree = [0] * n

    def query(self, i):
        ret = 0
        while i:
            ret += self.tree[i]
            i &= i - 1
        return ret

    def add(self, i):
        while i < len(self.tree):
            self.tree[i] += 1
            i += i & -i

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        srt = sorted(set(nums))
        a1 = [nums[0]]
        a2 = [nums[1]]
        m = len(srt)
        f1 = Fenwick(m + 1)
        f2 = Fenwick(m + 1)
        f1.add(bisect_right(srt, nums[0]))
        f2.add(bisect_right(srt, nums[1]))
        for i in range(2, len(nums)):
            x = nums[i]
            rank = bisect_right(srt, x)
            g1 = len(a1) - f1.query(rank)
            g2 = len(a2) - f2.query(rank)
            if g1 > g2 or g1 == g2 and len(a1) <= len(a2):
                f1.add(rank)
                a1.append(x)
            else:
                f2.add(rank)
                a2.append(x)
        a1 += a2
        return a1
