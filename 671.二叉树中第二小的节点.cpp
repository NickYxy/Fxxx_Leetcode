/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int helper(TreeNode* root, int minVal) {
        // 问题可以转化为求左右子树的最小值，如果左右子树最小值都大于根节点的值取较小的值。其他情况取左右子树较大的值
        // 1.没有必要记录最小的值，因为最小的一定是根结点。
        // 2.递归找到比根结点大的值时可以立即返回，不用再遍历当前节点下面的子节点，因为子节点的值不可能比它小。
        if (!root) return -1;
        if (root->val > minVal) return root->val;
        int l = helper(root->left,  minVal);
        int r = helper(root->right, minVal);
        if (l!= -1 && r != -1) return min(l, r);
        else return max(l, r);
    }

    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root->val);
    }
};
// @lc code=end

