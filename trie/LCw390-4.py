# https://leetcode.cn/problems/longest-common-suffix-queries/
from typing import *

class Node:
    __slots__ = ['children', 'idx', 'len']

    def __init__(self):
        self.children = [None] * 26
        self.idx = -1
        self.len = -1

class Trie:
    def __init__(self) -> None:
        self.root = Node()
        self.root.idx = 0
    
    def insert(self, val, idx):
        cur = self.root
        if cur.len == -1 or len(val) < cur.len:
            cur.idx = idx
            cur.len = len(val)
        for ch in reversed(val):
            i = ord(ch) - ord('a')
            if cur.children[i] is None:
                cur.children[i] = Node()
            cur = cur.children[i]
            if cur.idx == -1 or len(val) < cur.len:
                cur.idx = idx
                cur.len = len(val)
    
    def search(self, val):
        cur = self.root
        for ch in reversed(val):
            i = ord(ch) - ord('a')
            if cur.children[i] is None:
                break
            cur = cur.children[i]
        return cur.idx


class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        t = Trie()
        for i, w in enumerate(wordsContainer):
            t.insert(w, i)
        ans = []
        for q in wordsQuery:
            ans.append(t.search(q))
        return ans