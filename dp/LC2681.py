# https://leetcode.cn/problems/power-of-heroes/
class Solution:
    def sumOfPower(self, nums: List[int]) -> int:
        MOD = 10**9+7
        nums.sort()
        n = len(nums)
        dp = 0  # sum of min(sequence ending with i)
        pf_dp = 0
        ans = 0
        for i in range(n):
            dp = nums[i] + pf_dp
            pf_dp = pf_dp + dp
            ans = (ans + nums[i] * nums[i] * dp) % MOD
        return ans
