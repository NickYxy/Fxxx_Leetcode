/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    vector<int> res;
    vector<int> path;
    int sumNumbers(TreeNode* root) {
        path.push_back(root->val);
        dfs(root);
        for (int i = 1; i < res.size(); i ++) res[0] += res[i];
        return res[0];
    }

    void dfs(TreeNode* root) {
        if (!root->left && !root->right) {
            int temp = 0;
            for (int i = 0; i< path.size(); i ++) temp = path[i] + 10 * temp;
            res.push_back(temp);
        }

        if (root->left) {
            path.push_back(root->left->val);
            dfs(root->left);
            path.pop_back();
        }

        if (root->right) {
            path.push_back(root->right->val);
            dfs(root->right);
            path.pop_back();
        }
    }
};
// @lc code=end

