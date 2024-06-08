// https://leetcode.cn/problems/permutations-ii/
#include <bits/stdc++.h>

using namespace std;

// 3 3 3
/*
3   ->  3   ->  3
3       3
3
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur(n), vis(n);
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(cur);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j] || (j && nums[j] == nums[j - 1] && !vis[j - 1])) {
                    // ensure duplicates are used in one order
                    // use one only if previous one is used
                    continue;
                }
                cur[i] = nums[j];
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        };
        dfs(0);
        return ans;
    }
};