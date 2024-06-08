// https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int MOD = 1e9 + 7;
        int ht = target / 2;
        if (ht >= n) {
            // 1 ~ n
            return (1ll * (n + 1) * n / 2) % MOD;
        }
        // 1 ~ ht, t ~ t + (n - ht + 1)
        return (1ll * (ht + 1) * ht / 2 + (n - ht) * (2ll * target + n - ht - 1) / 2) % MOD;
    }
};