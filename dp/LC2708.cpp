#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f1(n); // max
        vector<int> f2(n); // min
        f1[0] = nums[0];
        f2[0] = nums[0];
        for (int i=1;i<n;++i){
            if (nums[i] < 0) {
                f1[i] = max(f1[i-1], f2[i-1]*nums[i]);
                f2[i] = min(f2[i-1], f1[i-1]*nums[i]);
            } else {
                f1[i] = max(f1[i-1], f1[i-1]*nums[i]);
                f2[i] = min(f2[i-1], f2[i-1]*nums[i]);
            }
        }
        return f1[n-1];
    }
};