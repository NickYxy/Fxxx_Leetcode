/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    unordered_map<int, int> mp;
    int treeSum(TreeNode* root) {
        if (!root) return 0;
        int left, right;
        if (root->left) left = treeSum(root->left); else left = 0;
        if (root->right) right = treeSum(root->right); else right = 0;
        int total = root->val + left + right;
        mp[total] ++;
        return total;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        treeSum(root);
        vector<int> ans;
        int mx = 0;
        for (auto [sum, cnt] : mp) {
            if (cnt < mx) continue;
            if (cnt > mx) {
                mx = cnt;
                ans.clear();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
// @lc code=end

