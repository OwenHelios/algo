// https://leetcode.cn/problems/last-stone-weight-ii/
#include <bits/stdc++.h>

using namespace std;

/*
result = abs(abs(a1 - a2) - a3) - a4 ...
=> pick +/- for each stone so that sum -> 0
=> pick subset of stones so that sum -> total/2
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1);
        for (int &num : stones) {
            for (int i = target; i >= num; --i) {
                dp[i] = max(dp[i], dp[i - num] + num);
            }
        }
        return sum - 2 * dp[target];
    }
};