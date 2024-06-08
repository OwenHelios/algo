// https://leetcode.cn/problems/minimum-time-to-revert-word-to-initial-state-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int n = s.size();
        vector<int> z(n, 0); // s[i : i + z[i]] == s[: z[i]]
        int l = 0, r = 0; // s[l : r + 1] == s[: r - l + 1]
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
                l = i;
                r = i + z[i] - 1;
            }
            if (i % k == 0 && z[i] >= n - i) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};

/* 
        a   b   a   c   a   b   a
z[]     0   0   1   0   3   0   1

if i <= r:

z[i - l] < r - i + 1:
a b c d a b e f a b c d a b e f g
                l             r
       i-l              i

z[i - l] > r - i + 1:
a   b   c   a   b   c   a   b   d
            l               r
                        i


a   b   c  d   a   b  e  f  a   b   c  d   a   b  c  d  a b e f
                            l                  r
                                           i
 */