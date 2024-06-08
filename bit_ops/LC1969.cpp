// https://leetcode.cn/problems/minimum-non-zero-product-of-the-array-elements/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pow(long long x, long long y, int mod) {
        int ans = 1;
        while (y) {
            x %= mod;
            if (y & 1) {
                ans = 1ll * ans * x % mod;
            }
            y >>= 1;
            x *= x;
        }
        return ans;
    }

    int minNonZeroProduct(int p) {
        int MOD = 1e9 + 7;
        long long n = (1ll << p) - 1;
        return n % MOD * pow(n - 1, n >> 1, MOD) % MOD;
    }
};