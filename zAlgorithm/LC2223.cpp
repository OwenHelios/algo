// https://leetcode.cn/problems/sum-of-scores-of-built-strings/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> z(n, 0);
        long long ans = n;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
                z[i]++;
                l = i;
                r = i + z[i] - 1;
            }
            ans += z[i];
        }
        return ans;
    }
};
