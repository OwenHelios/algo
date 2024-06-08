#include <bits/stdc++.h>
// https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/
using namespace std;
#define i64 long long

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int x, int y) {
            return nums2[x] < nums2[y];
        });
        vector<int> dp(n+1, 0);
        for(int i=0;i<n;++i){
            int num1 = nums1[ids[i]];
            int num2 = nums2[ids[i]];
            for (int j=n;j>0;--j){
                dp[j] = max(dp[j-1] + num1 + num2*j, dp[j]);
            }
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for(int t=0;t<=n;++t){
            if (s1 + t*s2 - dp[t] <= x) return t;
        }
        return -1;
    }
};

int main(){
    return 0;
}
