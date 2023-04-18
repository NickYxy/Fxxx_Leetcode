/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int ans = INT_MIN;
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val, root->val);
        return ans;
    }
    // dfs深搜的时候维护一个最大值和最小值即可，这样也避免了abs运算
    void dfs(TreeNode* root, int maxv, int minv) {
        if (!root) return;
        maxv = max(maxv, root->val);
        minv = min(minv, root->val);
        dfs(root->left, maxv, minv);
        dfs(root->right, maxv, minv);
        ans = max(ans, maxv - minv);
    }
};
// @lc code=end

