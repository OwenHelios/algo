# https://leetcode.cn/problems/maximum-strong-pair-xor-ii/
from collections import defaultdict
from typing import *


class Node:
    __slots__ = 'children', 'cnt'

    def __init__(self):
        self.children = [None, None] # left and right subtree
        self.cnt = 0 # size of tree with self as root

class Trie:
    HIGH_BIT = 19

    def __init__(self) -> None:
        self.root = Node()
    
    def insert(self, val):
        cur = self.root
        for i in range(self.HIGH_BIT, -1, -1):
            bit = (val >> i) & 1
            if cur.children[bit] is None:
                cur.children[bit] = Node()
            cur.children[bit].cnt += 1
            cur = cur.children[bit]
    
    def remove(self, val):
        # val has to exist before removing
        cur = self.root
        for i in range(self.HIGH_BIT, -1, -1):
            bit = (val >> i) & 1
            cur.children[bit].cnt -= 1
            cur = cur.children[bit]
    
    def search(self, val):
        cur = self.root
        ret = 0
        new_ret = 0
        for i in range(self.HIGH_BIT, -1, -1):
            new_ret = ret | (1 << i)
            bit = (val >> i) & 1
            if cur.children[bit ^ 1] is None or cur.children[bit ^ 1].cnt == 0:
                cur = cur.children[bit]
            else:
                cur = cur.children[bit ^ 1]
                ret = new_ret
        return ret

class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        l = 0
        ans = 0
        trie = Trie()
        for r in range(n):
            while nums[l] * 2 < nums[r]:
                trie.remove(nums[l])
                l += 1
            trie.insert(nums[r])
            ans = max(ans, trie.search(nums[r]))
        return ans