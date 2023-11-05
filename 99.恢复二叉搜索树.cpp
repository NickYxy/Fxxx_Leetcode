/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* t1 = nullptr, *t2 = nullptr;
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        dfs(root, pre);
        swap(t1->val, t2->val);
    }

    void dfs(TreeNode* root, TreeNode* &pre) {
        if (!root) return;
        dfs(root->left, pre);
        if (pre && pre->val > root->val && !t1) t1 = pre;
        if (t1 && pre->val > root->val) t2 = root;
        pre = root;
        dfs(root->right, pre);
    }
};
// @lc code=end

