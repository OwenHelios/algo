# https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/
from typing import *
# bw125-3

class Solution:
    def countPairsOfConnectableServers(self, edges: List[List[int]], signalSpeed: int) -> List[int]:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        ans = [0] * n
        for i in range(n):
            other_branches = 0
            dist = [-1] * n
            dist[i] = 0
            for j, w in g[i]:
                cnt = 0
                dist[j] = w
                q = [j]
                while q:
                    tmp, q = q, []
                    for k in tmp:
                        cnt += dist[k] % signalSpeed == 0
                        for u, wu in g[k]:
                            if dist[u] == -1:
                                dist[u] = dist[k] + wu
                                q.append(u)
                ans[i] += cnt * other_branches
                other_branches += cnt
        return ans