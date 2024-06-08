// https://leetcode.cn/problems/distribute-candies-among-children-ii/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long c2(int n) {
        long long ret = n > 1 ? n * (n - 1) / 2 : 0;
        return ret;
    }
    long long distributeCandies(int n, int limit) {
        return c2(n + 2) - 3 * c2(n - (limit + 1) + 2) + 3 * c2(n - 2 * (limit + 1) + 2) - c2(n - 3 * (limit + 1) + 2);
    }
};

int main() {
    Solution sol;
    sol.distributeCandies(4, 1);
    return 0;
}