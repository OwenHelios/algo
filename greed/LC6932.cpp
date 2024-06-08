#include <bits/stdc++.h>
// https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/

using namespace std;
#define i64 long long
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [&](const auto &item1, const auto &item2) {
            return item1[0] > item2[0];
        });
        i64 total_profit = 0;
        i64 ans = 0;
        int n = items.size();
        unordered_set<int> vis;
        stack<int> duplicates;
        for (int i=0;i<n;++i){
            int profit = items[i][0];
            int category = items[i][1];
            if (i+1 <= k) {
                total_profit += profit;
                if (!vis.insert(category).second) {
                    duplicates.push(profit);
                }
            } else if(!duplicates.empty() && vis.insert(category).second) {
                total_profit -= duplicates.top();
                total_profit += profit;
                duplicates.pop();
            }
            i64 cnt = vis.size();
            ans = max(ans, cnt*cnt + total_profit);
        }
        return ans;
    }
};