# https://leetcode.cn/problems/most-frequent-ids/
from typing import *
from collections import *
from heapq import *

class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        s = defaultdict(int)
        h = []
        n = len(freq)
        ans = [0] * n
        for i in range(n):
            s[nums[i]] += freq[i]
            heappush(h, (-s[nums[i]], nums[i])  )
            while s[h[0][1]] != -h[0][0]:
                heappop(h)
            if h:
                ans[i] = -h[0][0]
        return ans