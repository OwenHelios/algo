// https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/
// Fenwick Tree (Binary Indexed Tree): https://cp-algorithms.com/data_structures/fenwick.html
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

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            nums1[i] -= nums2[i];
        }
        vector<int> nums = nums1;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        Fenwick t(n + 1);
        long long ans = 0;
        for (int &num : nums1) {
            ans += t.query(upper_bound(nums.begin(), nums.end(), num + diff) - nums.begin());
            t.add(upper_bound(nums.begin(), nums.end(), num) - nums.begin());
        }
        return ans;
    }
};