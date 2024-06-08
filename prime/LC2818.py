from typing import *
MX = 100001
vals = [0] * MX
for i in range(2, MX):
    if vals[i]:
        continue
    for j in range(i, MX, i):
        vals[j] += 1


class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        MOD = 10**9+7
        n = len(nums)
        right = [n]*n  # index of first element > scores[i] to the right
        left = [-1] * n  # index of first element <= scores[i] to the left
        st = []
        for i, v in enumerate(nums):
            while st and vals[nums[st[-1]]] < vals[v]:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        ans = 1
        for num, i in sorted(zip(nums, range(n)), key=lambda z: -z[0]):
            amount = (i-left[i])*(right[i]-i)
            take = min(k, amount)
            ans = ans * pow(num, take, MOD) % MOD
            if k == take:
                break
            k -= take
        return ans % MOD


sol = Solution()
sol.maximumScore([3289, 2832, 14858, 22011], 6)
