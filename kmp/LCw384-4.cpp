#include <bits/stdc++.h>
// https://leetcode.cn/problems/number-of-subarrays-that-match-a-pattern-ii

using namespace std;
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size() - 1;
        int m = pattern.size();
        vector<int> kmp(m, 0);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = kmp[j - 1];
            }
            if (pattern[i] == pattern[j]) j++;
            kmp[i] = j;
        }
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            int diff = nums[i + 1] == nums[i] ? 0 : (nums[i + 1] > nums[i] ? 1 : -1);
            while (j > 0 && diff != pattern[j]) {
                j = kmp[j - 1];
            }
            if (diff == pattern[j]) j++;
            if (j == m) {
                ans++;
                j = kmp[j - 1];
            }
        }
        return ans;
    }
};