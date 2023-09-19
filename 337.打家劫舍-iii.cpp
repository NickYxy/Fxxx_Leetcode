/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        auto[root_rob, root_not_rob] = dfs(root);
        return max(root_rob, root_not_rob);
    }

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [l_rob, l_not_rob] = dfs(node->left);
        auto [r_rob, r_not_rob] = dfs(node->right);
        int rob = l_not_rob + r_not_rob + node->val;
        int not_rob = max(l_rob, l_not_rob) + max(r_rob, r_not_rob);
        return {rob, not_rob};
    }
};
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }

    vector<int> dfs(TreeNode* root) {
        //定义一个数组ans,长度为2,res[0]表示不抢该节点可获得最大值,res[1]表示抢劫该节点可获得最大值
        if (!root) return {0, 0};
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        return {max(l[0], l[1]) + max(r[0], r[1]), l[0] + r[0] + root->val};
    }
};

class Solution {
public:
    unordered_map<TreeNode* , int> umap; // 记录计算过的结果
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (umap[root]) return umap[root];

        int rval = root->val;
        if (root->left)  rval += rob(root->left->left)  + rob(root->left->right);
        if (root->right) rval += rob(root->right->left) + rob(root->right->right);

        int val2 = rob(root->left) + rob(root->right);
        umap[root] = max(rval, val2);
        return max(rval, val2);
    }
};
// @lc code=end

