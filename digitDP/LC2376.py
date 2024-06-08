from functools import lru_cache as cache


class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        s = str(n)

        @cache
        def f(i, mask, limit, started):
            if i == len(s):
                return int(started)
            res = 0
            if not started:
                res += f(i+1, mask, False, False)
            up = int(s[i]) if limit else 9
            for j in range(1 - int(started), up + 1):
                if not mask >> j & 1:
                    res += f(i + 1, mask | (1 << j), limit and j == up, True)
            return res
        return f(0, 0, True, False)


sol = Solution()
print(sol.countSpecialNumbers(20))
