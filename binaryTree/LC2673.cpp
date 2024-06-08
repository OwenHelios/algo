#include <bits/stdc++.h>
// https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/
using namespace std;
#define i64 long long
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int lastParent = n / 2 - 1;
        for(int i=0;i<=lastParent;++i) {
            cost[2*i+1] += cost[i];
            cost[2*i+2] += cost[i];
        }
        int ans = 0;
        for(int i=lastParent;i>=0;--i) {
            ans += abs(cost[2*i+1]-cost[2*i+2]);
            cost[i] = max(cost[2*i+1], cost[2*i+2]);
        }
        return ans;
    }
};