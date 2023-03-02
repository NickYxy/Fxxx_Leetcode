/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            vector<int> path;
            int n = q.size();

            for (int i = 0 ; i < n; i ++) {
                auto node = q.front();
                q.pop();
                path.push_back(node->val);
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
            ans.push_back(path[0]);
        }
        return ans;
    }
};
// @lc code=end

