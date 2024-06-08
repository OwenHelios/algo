// https://leetcode.cn/problems/3sum
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int l = i + 1;
            int r = n - 1;
            if (nums[r - 1] + nums[r] < target) continue;
            if (nums[l] + nums[l + 1] > target) break;
            while (l < r) {
                if (nums[l] + nums[r] > target) {
                    r--;
                    continue;
                }
                if (nums[l] + nums[r] < target) {
                    l++;
                    continue;
                }
                while (l + 1 < r && nums[l + 1] == nums[l]) l++;
                while (l < r - 1 && nums[r - 1] == nums[r]) r--;
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 1; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int target = -nums[i] - nums[j];
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] < target) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                if (l < n && nums[l] == target) {
                    ans.push_back({nums[i], nums[j], nums[l]});
                }
            }
        }
        return ans;
    }
};