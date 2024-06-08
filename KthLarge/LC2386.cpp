// https://leetcode.cn/problems/find-the-k-sum-of-an-array
#include <bits/stdc++.h>

using namespace std;

// heap
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for (int &num : nums) {
            if (num < 0) {
                num = -num;
            } else {
                sum += num;
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        q.emplace(0, 0);
        while (--k) {
            auto [s, i] = q.top();
            q.pop();
            if (i < n) {
                q.emplace(s + nums[i], i + 1);
                if (i) {
                    q.emplace(s + nums[i] - nums[i - 1], i + 1);
                }
            }
        }
        return sum - q.top().first;
    }
};

// bisect
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for (int &num : nums) {
            if (num < 0) {
                num = -num;
            } else {
                sum += num;
            }
        }
        sort(nums.begin(), nums.end());
        auto check = [&](long long val) {
            int rank = 1;
            function<void(long long, int)> dfs = [&](long long cur, int i) {
                if (i == n || rank == k || cur + nums[i] > val) {
                    return;
                }
                rank++;
                dfs(cur + nums[i], i + 1);
                dfs(cur, i + 1);
            };
            dfs(0, 0);
            return rank == k;
        };
        long long left = 0;
        long long right = accumulate(nums.begin(), nums.end(), 0ll);
        while (left < right) {
            long long mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return sum - left;
    }
};