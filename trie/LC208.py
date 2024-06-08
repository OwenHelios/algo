# https://leetcode.cn/problems/implement-trie-prefix-tree/
from collections import defaultdict


class Node:
    __slots__ = ['next', 'term']

    def __init__(self) -> None:
        self.next = defaultdict(Node)
        self.term = False


class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        cur = self.root
        for ch in word:
            cur = cur.next[ch]
        cur.term = True

    def search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            if ch not in cur.next:
                return False
            cur = cur.next[ch]
        return cur.term

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for ch in prefix:
            if ch not in cur.next:
                return False
            cur = cur.next[ch]
        return True
