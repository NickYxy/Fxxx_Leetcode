/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }

    int getHeight(TreeNode* root) {
        if (!root) return true;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if (lh >= 0 && rh >= 0 && abs(lh - rh) <= 1) {
            return max(lh, rh) + 1;
        } else return -1;

    }
};


// @lc code=end

