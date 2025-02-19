// https://leetcode.cn/problems/last-stone-weight/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if (x > y) {
                q.push(x - y);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};