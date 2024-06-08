// https://leetcode.cn/problems/sudoku-solver
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool valid = false;
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> blocks(9, 0);
        vector<pair<int, int>> spaces;
        auto flip = [&](int i, int j, int x) {
            rows[i] ^= 1 << x;
            cols[j] ^= 1 << x;
            blocks[i / 3 * 3 + j / 3] ^= 1 << x;
        };
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                } else {
                    flip(i, j, board[i][j] - '0');
                }
            }
        }
        auto check = [&](int i, int j, int x) {
            return (rows[i] & (1 << x)) == 0 && (cols[j] & (1 << x)) == 0 && (blocks[i / 3 * 3 + j / 3] & (1 << x)) == 0;
        };
        function<void(int)> dfs = [&](int pos) {
            if (pos == spaces.size()) {
                valid = true;
                return;
            }
            auto &[i, j] = spaces[pos];
            for (int x = 1; x < 10; ++x) {
                if (!check(i, j, x)) continue;
                flip(i, j, x);
                board[i][j] = '0' + x;
                dfs(pos + 1);
                if (valid) return;
                flip(i, j, x);
                board[i][j] = '.';
            }
        };
        dfs(0);
    }
};

int main() {
    Solution sol;
    // vector<vector<char>> arg = {{'5','3','.','6','7','8','9','.','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};
    vector<vector<char>> arg = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    sol.solveSudoku(arg);
        // cout << res << endl;
    return 0;
}

// g++ algos\backtrack\LC37.cpp -std=c++17 -o main;.\main