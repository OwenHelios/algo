// https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/
#include <bits/stdc++.h>
using namespace std;

vector<bool> valid(1001);

bool check(int num) {
    string s = to_string(num);
    int n = s.size();
    function<bool(int, int)> dfs = [&](int i, int cur) {
        if (i == n && cur == num){
            return true;
        }
        for ()
    };
    return dfs();
}

class Solution {
public:
    int punishmentNumber(int n) {
        
    }
};