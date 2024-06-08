from functools import lru_cache as cache
# https://leetcode.cn/problems/count-stepping-numbers-in-range


class Solution:
    def countSteppingNumbers(self, low: str, high: str) -> int:
        MOD = 10**9+7

        def dp(s):
            @cache
            def f(i, last, limit, started):
                if i == len(s):
                    return int(started)
                res = 0
                if not started:
                    res += f(i+1, -1, False, False)
                up = int(s[i]) if limit else 9
                for j in range(1-int(started), up+1):
                    if not started or j == last - 1 or j == last + 1:
                        res += f(i+1, j, limit and j == up, True)
                return res
            return f(0, -1, True, False)
        return (dp(high) - dp(str(int(low)-1))) % MOD
