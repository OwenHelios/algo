// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int j = st.top();
                ans[j] = prices[j] - prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = prices[i] - prices[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};