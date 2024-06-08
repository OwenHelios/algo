#include <bits/stdc++.h>
// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string

using namespace std;
#define i64 long long
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> kmp(m, 0);
        /* 
        if kmp[i] = v, then
            needle[i - v + 1 : i + 1] == needle[: v]
         */
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = kmp[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            kmp[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = kmp[j - 1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};

/* 
h:  a   a   b   a   a   b   a   a   f   a
n:  a   a   b   a   a   f
p:  0   1   0   1   2   0
 */