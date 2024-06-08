# LC2316 https://leetcode.cn/problems/sum-of-prefix-scores-of-strings/
from collections import defaultdict
from typing import *


class Node:
    __slots__ = ['next', 'score', 'ids']

    def __init__(self):
        self.next = defaultdict(Node)
        self.score = 0
        self.ids = []


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = Node()
        for i, word in enumerate(words):
            cur = root
            for ch in word:
                cur = cur.next[ch]
                cur.score += 1
            cur.ids.append(i)
        ans = [0] * len(words)

        def dfs(node, acc):
            if node is None:
                return
            acc += node.score
            for id in node.ids:
                ans[id] = acc
            for child in node.next.values():
                dfs(child, acc)
        dfs(root, 0)
        return ans
