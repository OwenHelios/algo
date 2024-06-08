from functools import lru_cache as cache


class Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        def dp(num):
            s = str(num)

            @cache
            def f(i, dsum, limit, started):
                if i == len(s):
                    return int(started and min_sum <= dsum <= max_sum)
                res = 0
                if not started:
                    res += f(i+1, 0, 0, False)
                up = int(s[i]) if limit else 9
                for j in range(1 - int(started), up + 1):
                    if j + dsum <= max_sum:
                        res += f(i+1, dsum+j, limit and j == up, True)
                return res
            return f(0, 0, True, False)
        return dp(num2) - dp(num1)


sol = Solution()
print(sol.count(20))
