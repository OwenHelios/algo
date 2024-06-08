// https://leetcode.cn/problems/maximum-good-subarray-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int, long long> min_pref; // value: min prefix sum ending before [key]
        long long ans = LLONG_MIN;
        for (auto &num: nums) {
            auto it = min_pref.find(num + k);
            if (it != min_pref.end()) {
                ans = max(ans, sum + num - it->second);
            }
            it = min_pref.find(num - k);
            if (it != min_pref.end()) {
                ans = max(ans, sum + num - it->second);
            }
            it = min_pref.find(num);
            if (it == min_pref.end() || sum < it->second) {
                min_pref[num] = sum;
            }
            sum += num;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};


// // OVERTIME
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_multimap<int, int> mp;
//         mp.emplace(nums[n - 1], n - 1);
//         long long ans = INT64_MIN;
//         bool found = false;
//         vector<long long> suf(n + 1, 0);
//         suf[n - 1] = nums[n - 1];
//         for (int i = n - 2; i >= 0; i--)
//         {
//             suf[i] = suf[i + 1] + nums[i];
//             auto its = mp.equal_range(nums[i] + k);
//             for (auto it = its.first; it != its.second; ++it) {
//                 int j = it->second;
//                 ans = max(ans, suf[i] - suf[j + 1]);
//                 found = true;
//             }
//             its = mp.equal_range(nums[i] - k);
//             for (auto it = its.first; it != its.second; ++it) {
//                 int j = it->second;
//                 ans = max(ans, suf[i] - suf[j + 1]);
//                 found = true;
//             }
//             mp.emplace(nums[i], i);
//         }
//         return found ? ans : 0;
//     }
// };