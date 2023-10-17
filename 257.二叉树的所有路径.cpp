/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;

        dfs(root, ans, "");
        return ans;
        }

    void dfs(TreeNode* root, vector<string> &ans, string path) {
        path += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        if (root->left) dfs(root->left, ans, path + "->");
        if (root->right) dfs(root->right, ans, path + "->");
    }
};
// @lc code=end

