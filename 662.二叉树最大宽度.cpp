/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    // 把每个点包括空结点进行编号，第i个点的左孩子为2*i，右孩子为2*i+1，然后存储每层的编号最小值来计算就行了
    // 先存每层最左边的节点的编号，然后走右树，对每一层做结算
    typedef unsigned long long ll;
    ll ans = 0;
    unordered_map<int, ll> minValue;
    void dfs(TreeNode* root, int level, ll nodeindex) {
        if (!root) return;
        if (minValue.count(level) == 0) minValue[level] = nodeindex;
        ans = max(ans, nodeindex - minValue[level] + 1);
        dfs(root->left,  level + 1, nodeindex * 2);
        dfs(root->right, level + 1, nodeindex * 2 + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 1);
        return ans;
    }
};
// @lc code=end

