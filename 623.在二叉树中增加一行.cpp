/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (d == 0 || d == 1) {
            auto t = new TreeNode(val);
            if (d == 1) t->left = root;
            else t->right = root;
            return t;
        }

        if (root && d > 1) {
            root->left  = addOneRow(root->left, val, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, val, d > 2 ? d - 1 : 0);
        }

        return root;
    }
};
// @lc code=end

