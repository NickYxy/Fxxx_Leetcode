/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        int ans = 0, max_v = INT_MIN, depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            depth ++;
            int sum = 0;
            int n = q.size();
            for (int i = 0; i < n; ++ i) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > max_v) {
                ans = depth;
                max_v = sum;
            }
        }

        return ans;
    }
};
// @lc code=end

