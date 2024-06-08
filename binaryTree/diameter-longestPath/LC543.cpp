// https://leetcode.cn/problems/diameter-of-binary-tree
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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return -1;
            int ldepth = dfs(node->left);
            int rdepth = dfs(node->right);
            ans = max(ans, ldepth + rdepth + 2);
            return max(ldepth, rdepth) + 1;
        };
        dfs(root);
        return ans;
    }
};

class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, -1};
        auto [ldist, ldepth] = dfs(root->left);
        auto [rdist, rdepth] = dfs(root->right);
        return {max({ldist, rdist, ldepth + rdepth + 2}), max(ldepth, rdepth) + 1};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};