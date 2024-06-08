// https://leetcode.cn/problems/find-a-value-of-a-mysterious-function-closest-to-target/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> cur;
        int ans = INT_MAX;
        for (auto &a : arr) {
            cur.insert(cur.begin(), a);
            size_t i = 0;
            while (i < cur.size()) {
                cur[i] &= a;
                if (cur[i] == target) return 0;
                ans = min(ans, abs(target - cur[i]));
                if (cur[i++] < target) {
                    break;
                }
            }
            cur.resize(i);
            cur.erase(unique(cur.begin(), cur.end()), cur.end());
        }
        return ans;
    }
};

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> cur;
        int ans = INT_MAX;
        for (auto &a : arr) {
            cur.insert(cur.begin(), a);
            size_t k = 0;
            for (size_t i = 0; i < cur.size(); ++i) {
                cur[i] &= a;
                if (cur[i] == target) return 0;
                if (i && cur[i] == cur[i - 1]) {
                    continue;
                }
                ans = min(ans, abs(target - cur[i]));
                cur[k++] = cur[i];
                if (cur[i] < target) {
                    break;
                }
            }
            cur.resize(k);
        }
        return ans;
    }
};

// slower
// class Solution {
// public:
//     int closestToTarget(vector<int>& arr, int target) {
//         set<int, greater<int>> cur;
//         int ans = INT_MAX;
//         for (auto &a : arr) {
//             set<int, greater<int>> tmp;
//             ans = min(ans, abs(a - target));
//             tmp.insert(a);
//             for (auto &c : cur) {
//                 int x = c & a;
//                 ans = min(ans, abs(x - target));
//                 if (x <= target) {
//                     break;
//                 }
//                 tmp.insert(x);
//             }
//             cur = tmp;
//         }
//         return ans;
//     }
// };