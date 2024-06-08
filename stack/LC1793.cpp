// https://leetcode.cn/problems/maximum-score-of-a-good-subarray
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        // left[i] = max(j: j < i, nums[j] < nums[i])
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        // right[i] = min(j: j > i, nums[j] < nums[i])
        vector<int> right(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // left[i] + 1 <= k <= right[i] - 1
            if (left[i] >= k || right[i] <= k) {
                continue;
            }
            ans = max(ans, (right[i] - 1 - left[i]) * nums[i]);
        }
        return ans;
    }
};