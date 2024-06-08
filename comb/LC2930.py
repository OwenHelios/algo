# https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/
from collections import *
from copy import copy, deepcopy
from heapq import *
from typing import *

class Solution:
    def stringCount(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        no_l = pow(25, n, MOD)
        no_ee = pow(25, n, MOD) + n * pow(25, n - 1, MOD)
        no_t = no_l
        no_l_t = pow(24, n, MOD)
        no_l_ee = pow(24, n, MOD) + n * pow(24, n - 1, MOD)
        no_t_ee = no_l_ee
        no_leet = pow(23, n, MOD) + n * pow(23, n - 1, MOD)
        return (pow(26, n, MOD) - no_l - no_ee - no_t + no_l_ee + no_l_t + no_t_ee - no_leet) % MOD
