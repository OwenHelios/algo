// https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-ii/
#include <bits/stdc++.h>
using namespace std;

/*
(x0, y0) top left
(xi, yi) bottom right
no other points in rectangle if yi <= y0 && yi > max(y1,...,yi-1)
*/
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto &a, auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int mx = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[j][1] <= points[i][1] && points[j][1] > mx) {
                    ans++;
                    mx = points[j][1];
                }
            }
        }
        return ans;
    }
};