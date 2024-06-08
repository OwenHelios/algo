# https://leetcode.cn/problems/permutations
from typing import *


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n = len(nums)
        path = [0] * n
        used = [False] * n

        def dfs(i):
            if i == n:
                ans.append(path.copy())
                return
            for j in range(n):
                if used[j]:
                    continue
                path[j] = nums[i]
                used[j] = True
                dfs(i+1)
                used[j] = False
        dfs(0)
        return ans
