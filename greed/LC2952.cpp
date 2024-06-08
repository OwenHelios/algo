// https://leetcode.cn/problems/minimum-number-of-coins-to-be-added
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int cur = 1; // 0~(cur - 1) obtainable
        int ans = 0;
        int i = 0;
        int n = coins.size();
        while (cur <= target) {
            if (i < n && coins[i] <= cur) {
                cur += coins[i++];
            } else {
                cur = 2 * cur;
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int cur = 0; // 0~cur obtainable
        int ans = 0;
        for (int &c : coins) {
            while (cur < c - 1) {
                cur = 2 * cur + 1;
                ans++;
            }
            if (cur >= target) {
                break;
            }
            cur += c;
        }
        while (cur < target) {
            cur = 2 * cur + 1;
            ans++;
        }
        return ans;
    }
};