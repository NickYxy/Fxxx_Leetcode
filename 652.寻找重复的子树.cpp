/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 采用将二叉树序列化的形式，建立哈希表，统计每次出现的次数，添加到结果集当中
        vector<TreeNode*> ans;
        unordered_map<string, int> mp;
        helper(root, ans, mp);
        return ans;
    }

    string helper(TreeNode* root, vector<TreeNode*>& ans, unordered_map<string, int>& mp) {
        string str;
        if (!root) return "#";
        str = to_string(root->val) + ' ' + helper(root->left, ans, mp) + ' ' + helper(root->right, ans, mp);
        if (mp[str] == 1) ans.push_back(root);
        mp[str] ++;
        return str;
    }
};
// @lc code=end

