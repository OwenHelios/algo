// https://leetcode.cn/problems/shortest-common-supersequence
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int f[n1 + 1][n2 + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n1; ++i) {
            f[i + 1][0] = i + 1;
        }
        for (int j = 0; j < n2; ++j) {
            f[0][j + 1] = j + 1;
        }
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (str1[i] == str2[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                } else {
                    f[i + 1][j + 1] = min(f[i][j + 1] + 1, f[i + 1][j] + 1);
                }
            }
        }
        string ans;
        int i = n1 - 1;
        int j = n2 - 1;
        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i--;
                j--;
            } else if (f[i + 1][j + 1] == f[i][j + 1] + 1) {
                ans += str1[i--];
            } else {
                ans += str2[j--];
            }
        }
        reverse(ans.begin(), ans.end());
        return str1.substr(0, i + 1) + str2.substr(0, j + 1) + ans;
    }
};