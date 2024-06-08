// https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/
#include <bits/stdc++.h>

using namespace std;

// bisect
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        auto check = [&](int limit) {
            int cnt = 0;
            int i = m - 1;
            int j = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= limit) {
                    cnt += i + 1;
                    j++;
                } else {
                    i--;
                }
            }
            return cnt >= k;
        };
        int l = matrix[0][0]; // min
        int r = matrix[m - 1][n - 1]; // max
        while (l < r) {
            int mid = l + (r - l) / 2; // (l + r) / 2 round towards 0
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        for (int i = 0; i < m; ++i) {
            q.emplace(matrix[i][0], i, 0);
        }
        while (--k) {
            auto [v, i, j] = q.top();
            q.pop();
            if (j + 1 < n) {
                q.emplace(matrix[i][j + 1], i, j + 1);
            }
        }
        return get<0>(q.top());
    }
};