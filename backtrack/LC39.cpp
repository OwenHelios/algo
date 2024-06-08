// https://leetcode.cn/problems/combination-sum
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> cur;
        int sum = 0;
        function<void(int)> dfs = [&] (int i) {
            if (sum > target) return;
            if (sum == target) {
                ans.push_back(cur);
                return;
            }
            for (int j = i; j < n; ++j) {
                sum += candidates[j];
                cur.push_back(candidates[j]);
                dfs(j);
                sum -= candidates[j];
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};