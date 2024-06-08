// https://leetcode.cn/problems/next-greater-element-i/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int n = nums2.size();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans = nums1;
        for (int &num : ans) {
            if (mp.find(num) == mp.end()) {
                num = -1;
            } else {
                num = mp[num];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans = nums1;
        for (int &num : ans) {
            if (mp.find(num) == mp.end()) {
                num = -1;
            } else {
                num = mp[num];
            }
        }
        return ans;
    }
};
