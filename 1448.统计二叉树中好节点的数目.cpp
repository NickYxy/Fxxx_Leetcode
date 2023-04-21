/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int goodNodes(TreeNode* root) {
        int cnt = 0, max_v = -10001;
        dfs(root, max_v, cnt);
        return cnt;
    }

    void dfs(TreeNode* root, int max_v, int& cnt) {
        if (!root) return;

        max_v = max(max_v, root->val);
        if (max_v <= root->val) cnt ++;

        dfs(root->left, max_v, cnt);
        dfs(root->right, max_v, cnt);
    }
};
// @lc code=end

