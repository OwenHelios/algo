// https://leetcode.cn/problems/permutations/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cur(n);
        vector<bool> used(n);
        function<void(int)> dfs = [&] (int i){
            if (i == n) {
                ans.push_back(cur);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                cur[i] = nums[j];
                used[j] = true;
                dfs(i + 1);
                used[j] = false;
            }
        };
        dfs(0);
        return ans;
    }
};