// https://leetcode.cn/problems/count-stepping-numbers-in-range
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9+7;
    int dp(string s) {
        int n = s.size();
        map<pair<int, int>, int> mem;
        function<int(int, int, bool, bool)> f = [&](int i, int last, bool limit, bool started) {
            int res = 0;
            if (i == n) {
                res = started;
                mem[make_pair(i, last)] = res;
                return res;
            }
            if (!limit && started && mem.find(make_pair(i, last)) != mem.end()) return mem[make_pair(i, last)];
            if (!started) res += f(i+1, -1, false, false);
            int up = limit ? (s[i] - '0') : 9;
            for (int j = 1-started; j <= up; ++j) {
                if (!started || abs(j - last) == 1) {
                    res = (res + f(i+1, j, limit && j == up, true)) % MOD;
                }
            }
            mem[make_pair(i, last)] = res;
            return res;
        };
        return f(0, -1, true, false);
    }

    bool valid(string s) {
        int n = s.size();
        for (int i=1;i<n;++i){
            if (abs(s[i] - s[i-1]) != 1) return false;
        }
        return true;
    }

    int countSteppingNumbers(string low, string high) {
        return (dp(high) - dp(low) + valid(low) + MOD) % MOD;
    }
};