// https://leetcode.cn/problems/daily-temperatures/
#include <bits/stdc++.h>

using namespace std;

// Monotonic Stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int j = st.top();
                ans[j] = i - j;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};