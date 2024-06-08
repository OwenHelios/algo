// https://leetcode.cn/problems/minimize-manhattan-distances/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> s1;
        multiset<int> s2;
        for (auto &p : points) {
            s1.insert(p[0] + p[1]);
            s2.insert(p[0] - p[1]);
        }
        int ans = INT_MAX;
        for (auto &p : points) {
            s1.erase(s1.find(p[0] + p[1]));
            s2.erase(s2.find(p[0] - p[1]));
            // // extract removes one, erase removes all
            // s1.extract(p[0] + p[1]);
            // s2.extract(p[0] - p[1]);
            ans = min(ans, max(*s1.rbegin() - *s1.begin(), *s2.rbegin() - *s2.begin()));
            s1.insert(p[0] + p[1]);
            s2.insert(p[0] - p[1]);
        }
        return ans;
    }
};