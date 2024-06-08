#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[0];
        function<void(int, long long, bool)> dfs = [&](int i, long long prod, bool empty) {
            if(i==n) {
                if(!empty){
                    ans = max(ans, prod);
                }
                return;
            }
            dfs(i+1, prod, empty);
            dfs(i+1, prod*nums[i], false);
        };
        dfs(0, 1, true);
        return ans;
    }
};