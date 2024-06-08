// https://leetcode.cn/problems/earliest-second-to-mark-indices-i/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        vector<int> last(n, -1);
        auto check = [&](int i) {
            fill(last.begin(), last.end(), -1);
            int cnt = 0;
            for (int j = 0; j <= i; ++j) {
                int idx = changeIndices[j] - 1;
                cnt += last[idx] == -1;
                last[idx] = j;
            }
            if (cnt < n) return false;
            int have = 0;
            for (int j = 0; j <= i; ++j) {
                int idx = changeIndices[j] - 1;
                if (j != last[idx]) {
                    have++;
                } else if (have < nums[idx]) {
                    return false;
                } else {
                    have -= nums[idx];
                }
            }
            return true;
        };
        int l = n - 1;
        int r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r == m ? -1 : r + 1;
    }
};