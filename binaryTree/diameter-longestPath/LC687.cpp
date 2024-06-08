// https://leetcode.cn/problems/longest-univalue-path/
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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return -1;
            int l = dfs(node->left) + 1;
            int r = dfs(node->right) + 1;
            if (node->left && node->left->val != node->val) {
                l = 0;
            }
            if (node->right && node->right->val != node->val) {
                r = 0;
            }
            ans = max(ans, l + r);
            return max(l, r);
        };
        dfs(root);
        return ans;
    }
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            int l = 0, r = 0;
            if (node->left) {
                int ret = dfs(node->left);
                if (node->left->val == node->val) {
                    l = ret + 1;
                }
            }
            if (node->right) {
                int ret = dfs(node->right);
                if (node->right->val == node->val) {
                    r = ret + 1;
                }
            }
            ans = max(ans, l + r);
            return max(l, r);
        };
        dfs(root);
        return ans;
    }
};