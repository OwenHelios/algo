// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
#include <bits/stdc++.h>

using namespace std;

class Fenwick {
public:
    vector<int> t;
    int n;
    Fenwick(int _n) : n(_n), t(_n + 1) {}

    void add(int i) {
        while (i <= n) {
            t[i]++;
            i += i & -i;
        }
    }

    int query(int i) {
        int ret = 0;
        while (i) {
            ret += t[i];
            i -= i & -i;
            // i &= i - 1;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        auto srt = nums;
        sort(srt.begin(), srt.end());
        int n = nums.size();
        Fenwick f(n);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int rank = upper_bound(srt.begin(), srt.end(), nums[i]) - srt.begin();
            f.add(rank);
            ans[i] = f.query(rank - 1);
        }
        return ans;
    }
};