// https://leetcode.cn/problems/binary-tree-maximum-path-sum/
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
    int MN = -1e8;
    int maxPathSum(TreeNode* root) {
        int ans = MN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) { // max path sum from node to any children
            if (!node) return 0;
            int l = dfs(node->left);
            int r = dfs(node->right);
            ans = max(ans, l + r + node->val);
            return max(max(l, r) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};

class Solution {
public:
    int MN = -1e8;
    int maxPathSum(TreeNode* root) {
        int ans = MN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) { // max path sum from node to any children
            if (!node) return 0;
            int l = max(dfs(node->left), 0);
            int r = max(dfs(node->right), 0);
            ans = max(ans, l + r + node->val);
            return max(l + node->val, r + node->val);
        };
        dfs(root);
        return ans;
    }
};