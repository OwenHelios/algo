// https://leetcode.cn/problems/car-pooling/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> delta(1002);
        int start = 1001;
        int end = 0;
        for (auto &t : trips) {
            delta[t[1]] += t[0];
            delta[t[2]] -= t[0];
            start = min(start, t[1]);
            end = max(end, t[1]);
        }
        int cur = 0;
        for (int i = start; i <= end; ++i) {
            cur += delta[i];
            if (cur > capacity) return false;            
        }
        return true;
    }
};