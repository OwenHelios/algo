// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        set<tuple<int, int, int>> s;
        s.emplace(nums1[0] + nums2[0], 0, 0);
        vector<vector<int>> ans;
        while (k--) {
            auto [val, i, j] = *s.begin();
            s.erase(s.begin());
            ans.push_back({nums1[i], nums2[j]});
            if (j == 0 && i != n1 - 1) {
                s.emplace(nums1[i + 1] + nums2[j], i + 1, j);
            }
            if (j != n2 - 1) {
                s.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(nums1[0] + nums2[0], 0, 0);
        vector<vector<int>> ans;
        while (k--) {
            auto [val, i, j] = q.top();
            q.pop();
            vector<int> cur = {nums1[i], nums2[j]};
            ans.push_back(cur);
            if (j == 0 && i < n1 - 1) {
                // only push i when j==0, prevent duplicates
                q.emplace(nums1[i + 1] + nums2[j], i + 1, 0);
            }
            if (j < n2 - 1) {
                q.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};