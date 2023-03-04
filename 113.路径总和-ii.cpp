/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return ans;
        dfs(root, targetSum, path);
        return ans;
    }

    void dfs(TreeNode* root, int cur, vector<int> path) {
        path.push_back(root->val);
        cur -= root->val;
        if (!root->left && !root->right && cur == 0) {
            ans.push_back(path);
            return;
        }

        if (root->left) dfs(root->left, cur, path);
        if (root->right) dfs(root->right, cur, path);
    }
};
// @lc code=end

