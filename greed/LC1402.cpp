// https://leetcode.cn/problems/reducing-dishes/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        int pref = 0;
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int ans = 0;
        for (int x: satisfaction) {
            pref += x;
            if (pref < 0) break;
            ans += pref;
        }
        return ans;
    }
};

