// https://leetcode.cn/problems/next-greater-element-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) {
            int j = i % n;
            while (!st.empty() && nums[j] > nums[st.top()]) {
                ans[st.top()] = nums[j];
                st.pop();
            }
            st.push(j);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; --i) {
            int j = i % n;
            while (!st.empty() && st.top() <= nums[j]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[j] = st.top();
            }
            st.push(nums[j]);
        }
        return ans;
    }
};