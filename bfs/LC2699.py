from typing import *


class Solution:
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        g = [[] for _ in range(n)]
        for i, j, w in edges:
            g[i].append((j, w))
            g[j].append((i, w))

        def ans(acc, k, x, y):
            if target - acc < k:
                return []
            res = []
            cnt = target - acc - k + 1
            for i, j, w in edges:
                if w == -1:
                    if set([i, j]) == set([x, y]):
                        res.append([i, j, cnt])
                    else:
                        res.append([i, j, 1])
                else:
                    res.append([i, j, w])
        q = [(source, 0, 0)]
        while q:
            tmp, q = q, []
            for node, acc, k in tmp:
                for i, w in g[node]:
                    if w == -1:
                        k += 1
                    else:
                        acc += w
                    q.append((i, acc, k))
                    if i == destination:
                        return ans(acc, k, node, i)
