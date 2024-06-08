// https://leetcode.cn/problems/course-schedule-iii/
#include <bits/stdc++.h>

using namespace std;
// 反悔贪心
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int sum = 0;
        for (auto &course : courses) {
            int duration = course[0];
            int last = course[1];
            if (sum + duration <= last) {
                sum += duration;
                q.push(duration);
            } else if (!q.empty() && duration < q.top()) {
                sum -= q.top() - duration;
                q.pop();
                q.push(duration);
            }
        }
        return q.size();
    }
};