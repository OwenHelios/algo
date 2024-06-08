from typing import *
from heapq import *
from math import *
from collections import *
from bisect import *
from itertools import *
from time import *
from sortedcontainers import SortedList


class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 10**9 + 7
        items = []
        for i in count(1):
            pwr = i**x
            if pwr > n:
                break
            items.append(pwr)
        dp = [1] + [0]*n
        for item in items:
            for j in range(n, item - 1, -1):
                dp[j] = (dp[j] + dp[j-item]) % MOD
        return dp[n]


sol = Solution()
res = sol.numberOfWays(10, 2)
print(res)
