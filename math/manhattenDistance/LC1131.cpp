// https://leetcode.cn/problems/maximum-of-absolute-value-expression/
#include <bits/stdc++.h>

using namespace std;

/* abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2) = max(
                                                    abs((x1 + y1 + z1) - (x2 + y2 + z2)),
                                                    abs((x1 - y1 + z1) - (x2 - y2 + z2)),
                                                    abs((x1 + y1 - z1) - (x2 + y2 - z2)),
                                                    abs((x1 - y1 - z1) - (x2 - y2 - z2))
                                                )
*/
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mx(4, INT_MIN);
        vector<int> mn(4, INT_MAX);
        int n = arr1.size();
        for (int i = 0; i < n; ++i) {
            mx[0] = max(mx[0], arr1[i] + arr2[i] + i);
            mx[1] = max(mx[1], arr1[i] - arr2[i] + i);
            mx[2] = max(mx[2], arr1[i] + arr2[i] - i);
            mx[3] = max(mx[3], arr1[i] - arr2[i] - i);
            mn[0] = min(mn[0], arr1[i] + arr2[i] + i);
            mn[1] = min(mn[1], arr1[i] - arr2[i] + i);
            mn[2] = min(mn[2], arr1[i] + arr2[i] - i);
            mn[3] = min(mn[3], arr1[i] - arr2[i] - i);
        }
        return max({mx[0] - mn[0], mx[1] - mn[1], mx[2] - mn[2], mx[3] - mn[3]});
    }
};