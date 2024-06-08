# https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/
from typing import *


class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        items.sort(key=lambda x: -x[0])  # profit max~min
        ans = total_profit = 0
        vis = set()
        duplicates = []
        for i, (profit, category) in enumerate(items):
            if i+1 <= k:
                total_profit += profit
                if category in vis:
                    duplicates.append(profit)
                else:
                    vis.add(category)
            elif category not in vis and duplicates:
                # profit already sorted so only consider new item if it's a new category AND there're duplicates in any existing category
                vis.add(category)
                total_profit -= duplicates.pop()
                total_profit += profit
            ans = max(ans, total_profit + len(vis)**2)
        return ans
