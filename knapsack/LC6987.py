# https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/
from typing import *


class Solution:
    # dp[][]
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        n = len(nums1)
        arr = sorted((nums2[i], nums1[i]) for i in range(n))
        # fix the elements to operate on, operate on index with larger nums2 last
        dp = [[0]*(n+1) for _ in range(n+1)]
        # dp[i][j]: deducted amount: considering the first i elements, after j operations (j <= n)
        for i in range(n):
            for j in range(1, n+1):
                num2, num1 = arr[i]
                # operating on nums1[i] VS not
                dp[i+1][j] = max(dp[i][j-1] + num1 + num2*j, dp[i][j])
        s1 = sum(nums1)
        s2 = sum(nums2)
        cur = s1
        for t in range(n+1):
            if cur - dp[n][t] <= x:
                return t
            cur += s2
        return -1


class Solution:
    # dp[]
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        n = len(nums1)
        arr = sorted((nums2[i], nums1[i]) for i in range(n))
        # fix the elements to operate on, operate on index with larger nums2 last
        dp = [0]*(n+1)
        # dp[i][j]: deducted amount: considering the first i elements, after j operations (j <= n)
        for num2, num1 in arr:
            for j in range(n, 0, -1):
                # operating on nums1[i] VS not
                dp[j] = max(dp[j-1] + num1 + num2*j, dp[j])
        s1 = sum(nums1)
        s2 = sum(nums2)
        cur = s1
        for t in range(n+1):
            if cur - dp[t] <= x:
                return t
            cur += s2
        return -1
