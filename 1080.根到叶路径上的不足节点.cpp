/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {

        return dfs(root, 0, limit);
    }

    TreeNode* dfs(TreeNode* root, int cur, int limit) {
        if (!root) return nullptr;
        cur += root->val;
        if (!root->left && !root->right) return cur < limit ? nullptr : root; // 叶子结点直接判断
        root->left = dfs(root->left,  cur, limit);
        root->right = dfs(root->right, cur, limit);
        if (root->left || root->right) return root; // 左右两个节点有一个满足就无须删除父节点
        return nullptr;
    }
};
// @lc code=end

