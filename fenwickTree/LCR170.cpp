// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
#include <bits/stdc++.h>

using namespace std;
class Fenwick {
private:
    vector<int> tree;
public:
    Fenwick(int n) : tree(n) {}

    int query(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i &= i - 1;
        }
        return ret;
    }

    void add(int i) {
        int n = tree.size();
        while (i < n) {
            tree[i]++;
            i += i & -i;
        }
    }
};

// sol 1
class Solution {
public:
    int reversePairs(vector<int>& record) {
        int n = record.size();
        vector<int> sorted = record;
        sort(sorted.begin(), sorted.end());
        Fenwick t(n + 1);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int rank = upper_bound(sorted.begin(), sorted.end(), record[i]) - sorted.begin();
            ans += t.query(rank - 1);
            t.add(rank);
        }
        return ans;
    }
};

// sol 2
class Solution {
public:
    int reversePairs(vector<int>& record) {
        int n = record.size();
        vector<int> sorted = record;
        sort(sorted.begin(), sorted.end());
        for (int &r : record) {
            r = upper_bound(sorted.begin(), sorted.end(), r) - sorted.begin();
            // or r = lower_bound(sorted.begin(), sorted.end(), r) - sorted.begin() + 1;
        }
        Fenwick t(n + 1);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += t.query(record[i] - 1);
            t.add(record[i]);
        }
        return ans;
    }
};