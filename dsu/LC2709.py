from typing import *


class dsu:
    def __init__(self, n) -> None:
        self.p = list(range(n))
        self.size = [1]*n

    def union(self, a, b):
        fa = self.find(a)
        fb = self.find(b)
        if fa == fb:
            return False
        self.p[fa] = self.p[fb]
        self.size[fb] += self.size[fa]

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]


MX = 10**5
lpf = [0]*(MX+1)

for i in range(2, MX+1):
    if lpf[i]:
        continue
    for j in range(i, MX+1, i):
        if not lpf[j]:
            lpf[j] = i


class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        uf = dsu(n+MX)

        for i in range(n):
            x = nums[i]
            while x > 1:
                p = lpf[x]
                x //= p
                while lpf[x] == p:
                    x //= p
                uf.union(i, n+p)
        s = set()
        for i in range(n):
            s.add(uf.find(i) - n)

        return len(s) == 1
