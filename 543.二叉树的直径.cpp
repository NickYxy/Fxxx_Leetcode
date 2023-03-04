/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
            dfs(root);
            return ans;
        }

        int dfs(TreeNode* root) {
            if (!root->left && !root->right) return 0;
            int leftSize = 0, rightSize = 0;
            if (root->left) leftSize = dfs(root->left) + 1;
            if (root->right) rightSize = dfs(root->right) + 1;
            ans = max(ans, leftSize + rightSize);
            return max(leftSize, rightSize);
        }
};
// @lc code=end

