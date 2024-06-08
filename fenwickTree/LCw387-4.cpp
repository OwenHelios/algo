// https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii/
#include <bits/stdc++.h>

using namespace std;
#define i64 long long

class Fenwick {
private:
    vector<int> tree;
public:
    Fenwick(int n) : tree(n) {}

    int query(int i) {
        int ret = 0;
        while (i) {
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

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> sorted = nums;
        vector<int> ranks = nums;
        sort(sorted.begin(), sorted.end());
        for (int &num : ranks) {
            num = upper_bound(sorted.begin(), sorted.end(), num) - sorted.begin();
        }
        int n = nums.size();
        Fenwick f1(n + 1);
        Fenwick f2(n + 1);
        vector<int> a1({nums[0]});
        vector<int> a2({nums[1]});
        f1.add(ranks[0]);
        f2.add(ranks[1]);
        for (int i = 2; i < n; ++i) {
            int g1 = a1.size() - f1.query(ranks[i]);
            int g2 = a2.size() - f2.query(ranks[i]);
            if (g1 > g2 || g1 == g2 && a1.size() <= a2.size()) {
                f1.add(ranks[i]);
                a1.push_back(nums[i]);
            } else {
                f2.add(ranks[i]);
                a2.push_back(nums[i]);
            }
        }
        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};