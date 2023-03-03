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
        } else return -1; // 提前裁剪

    }
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* node) {
        if (!node) return 0;
        int left  = getDepth(node->left);
        int right = getDepth(node->right);

        return max(left, right) + 1;
    }
};
// @lc code=end

