// https://leetcode.cn/problems/maximum-or/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        // spending all operations on one num is strictly better
        // because it creates max bit length
        int n = nums.size();
        vector<int> suffix(n+1);
        for(int i=n-1;i>=0;--i) {
            suffix[i] = suffix[i+1] | nums[i];
        }
        int prefix = 0;
        long long ans = 0;
        for(int i=0;i<n;++i) {
            long long cur = prefix | (long long)nums[i] << k | suffix[i+1];
            ans = max(ans, cur);
            prefix |= nums[i];
        }
        return ans;
    }
};
