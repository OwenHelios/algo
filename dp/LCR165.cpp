// https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int crackNumber(int ciphertext) {
        string s = to_string(ciphertext);
        int pre = 1;
        int cur = 1;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            int tmp = cur;
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '6') {
                cur = pre + cur;
            }
            pre = tmp;
        }
        return cur;
    }
};