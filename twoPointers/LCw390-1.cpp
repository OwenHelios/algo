// https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int left = 0;
        int n = s.size();
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
            while (cnt[s[i] - 'a'] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};