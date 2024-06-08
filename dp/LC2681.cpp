// https://leetcode.cn/problems/power-of-heroes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int MOD = 1e9+7;
        int ans = 0;
        int s = 0;
        sort(nums.begin(), nums.end());
        for(int num: nums) {
            s = (2ll*s + num) % MOD;
            ans = (1ll*num*s + ans) % MOD;
        }
        return ans;
    }
};