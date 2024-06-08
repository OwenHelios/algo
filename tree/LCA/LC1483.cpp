// https://leetcode.cn/problems/kth-ancestor-of-a-tree-node
#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
    vector<vector<int>> lift;
public:
    TreeAncestor(int n, vector<int>& parent) {
        int k = 32 - __builtin_clz(n); // 2^(k - 1) <= depth < 2^k
        lift.resize(k, vector<int>(n, -1));
        for (int i = 0; i < k; ++i) { // go up by 2^i levels
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    lift[0][j] = parent[j];
                    continue;
                } else if (lift[i - 1][j] != -1) {
                    // 2^i = 2^(i - 1) + 2^(i - 1)
                    lift[i][j] = lift[i - 1][lift[i - 1][j]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 32 - __builtin_clz(k) - 1; i >= 0 && node != -1; --i) {
            if (k >> i & 1) {
                node = lift[i][node];
            }
        }
        return node;
    }
};