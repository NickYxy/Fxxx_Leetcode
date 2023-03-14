/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 一个树是另一个树的子树 则
        //     要么这两个树相等
        //     要么这个树是左树的子树
        //     要么这个树hi右树的子树
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        return isSametree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSametree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        return s && t && s->val == t->val && isSametree(s->left, t->left) && isSametree(s->right, t->right);
    }
};
// @lc code=end

