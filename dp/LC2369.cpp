#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> valid(n + 1, false);
        valid[0] = true;
        for (int i = 1; i < n; ++i) {
            bool cond = nums[i] == nums[i - 1] && valid[i - 1] ||
            i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] && valid[i - 2] ||
            i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1 && valid[i - 2];
            if (cond) {
                valid[i + 1] = true;
            }
        }
        return valid[n];
    }
};