#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 20001));
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j){
                if (i==0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int tmp = 20001;
                for(int k=0;k<n;++k) {
                    if (j==k) continue;
                    tmp = min(tmp, dp[i-1][k]);
                }
                dp[i][j] = tmp + grid[i][j];
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int last_min = 0, last_next_min = 0, last_min_idx = 0;
        for (int i=0;i<n;++i) {
            int cur_min = INT_MAX, cur_next_min= INT_MAX;
            int cur, cur_min_idx;
            for (int j=0;j<n;++j) {
                if (j==last_min_idx) {
                    cur = last_next_min + grid[i][j];
                } else {
                    cur = last_min + grid[i][j];
                }
                if (cur < cur_min) {
                    cur_next_min = cur_min;
                    cur_min = cur;
                    cur_min_idx = j;
                } else if (cur < cur_next_min) {
                    cur_next_min = cur;
                }
            }
            last_min = cur_min;
            last_next_min = cur_next_min;
            last_min_idx = cur_min_idx;
        }
        return last_min;
    }
};
