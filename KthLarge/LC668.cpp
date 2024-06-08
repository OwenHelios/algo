// https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n;
        while (l < r) {
            int mid = (l + r) / 2;
            int i = mid / n;
            int cnt = i * n;
            while (++i <= m) {
                cnt += mid / i;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//         auto check = [&](int val) {
//             int i = val / n;
//             int cnt = i * n;
//             int lj = 1, rj = n - 1;
//             while (lj < rj) {
//                 int mid = (lj + rj) / 2;
//                 if (mid * (i + 1) < val) {
//                     lj = mid + 1;
//                 } else {
//                     rj = mid;
//                 }
//             }
//             while (++i <= m && i <= val) {
//                 while (lj && i * lj > val) {
//                     lj--;
//                 }
//                 cnt += lj;
//             }
//             return cnt >= k;
//         };
//         int l = 1;
//         int r = m * n;
//         while (l < r) {
//             int mid = (l + r) / 2;
//             if (check(mid)) {
//                 r = mid;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return l;
//     }
// };