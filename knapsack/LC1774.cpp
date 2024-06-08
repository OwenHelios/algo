// https://leetcode.cn/problems/closest-dessert-cost/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int> tc = {0};
        for (int &t : toppingCosts) {
            auto tmp = tc;
            for (auto &item : tmp) {
                tc.push_back(item + t);
                tc.push_back(item + 2 * t);
            }
        }
        tc.erase(unique(tc.begin(), tc.end()), tc.end());
        // unordered_set<int> tcs; // slower
        // tcs.insert(0);
        // for (int &t : toppingCosts) {
        //     auto tmp = tcs;
        //     for (auto &item : tmp) {
        //         tcs.insert(item + t);
        //         tcs.insert(item + 2 * t);
        //     }
        // }
        // vector<int> tc(tcs.begin(), tcs.end());
        sort(tc.begin(), tc.end());
        int n = tc.size();
        int ans = baseCosts[0];
        auto check = [&](int val) {
            if (abs(target - val) < abs(target - ans) || (abs(target - val) == abs(target - ans) && val < ans)) {
                ans = val;
            }
        };
        for (int &bc : baseCosts) {
            int diff = target - bc;
            if (diff < 0) {
                check(bc);
                continue;
            };
            int i = lower_bound(tc.begin(), tc.end(), diff) - tc.begin();
            if (i < n && tc[i] == diff) return target;
            for (int j = i - 1; j <= min(n - 1, i); ++j) {
                check(bc + tc[j]);
            }
        }
        return ans;
    }
};