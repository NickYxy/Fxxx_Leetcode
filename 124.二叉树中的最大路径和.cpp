/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return ans;
    }

    int getMax(TreeNode* node) {
        if (!node) return 0;
        auto left = max(0, getMax(node->left));
        auto right = max(0, getMax(node->right));
        ans = max(ans, left + right + node->val);
        return max(left, right) + node->val;
    }
};
// @lc code=end

