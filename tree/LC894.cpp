// https://leetcode.cn/problems/all-possible-full-binary-trees
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<TreeNode*>> f(11);
auto init = [] {
    f[1].push_back(new TreeNode());
    for (int i = 2; i < 11; ++i) { // total number of leaves
        for (int j = 1; j < i; ++j) { // leaves in left subtree, can't be 0 or i because full binary tree
            for (auto left : f[j]) {
                for (auto right : f[i - j]) {
                    f[i].push_back(new TreeNode(0, left, right));
                }
            }
        }
    }
    return 0;
} ();

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return n % 2 ? f[(n + 1) / 2] : vector<TreeNode*>();
    }
};