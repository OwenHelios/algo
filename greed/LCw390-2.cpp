// https://leetcode.cn/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int k) {
        int ans = k - 1;
        for (int i = 0; i < k; ++i) {
            // number of add operations
            ans = min(ans, i + (k - 1) / (i + 1));
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(int k) {
        int rt = max((int)sqrt(k - 1), 1);
        return min(rt - 1 + (k - 1) / rt, rt + (k - 1) / (rt + 1));
    }
};