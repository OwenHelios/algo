#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, pre = 0;
        for (int &num : nums) {
            int tmp = cur;
            cur = max(pre + num, cur);
            pre = tmp;
        }
        return cur;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pre = 0; // dp[i-1]
        int cur = nums[0];
        for (int i=1;i<n;++i) {
            // max profit ending with i 
            // picking nums[i] VS not
            int tmp = cur;
            cur = max(pre + nums[i], cur);
            pre = tmp;
        }
        return cur;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[1] = nums[0];
        for (int i=1;i<n;++i) {
            // max profit ending with i 
            // picking nums[i] VS not
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        }
        return dp[n];
    }
};


/*
WRONG ANSWER:
class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, pre = 0;
        for (int &num : nums) {
            int tmp = cur;
            cur = pre + num;
            pre = tmp;
        }
        return max(cur, pre);
    }
};
*/