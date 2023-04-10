/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // 最深叶子节点的最近公共祖先
        // 对于一个节点，如果左子树高度==右子树高度，这个节点就是答案，
        // 如果左子树高度<右子树高度，查找右子树，否则查找左子树
        if (!root) return nullptr;
        int left_depth = maxDepth(root->left), right_depth = maxDepth(root->right);
        if (left_depth == right_depth) return root;
        else if (left_depth < right_depth) return subtreeWithAllDeepest(root->right);
        else return subtreeWithAllDeepest(root->left);
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    }
};
// @lc code=end

