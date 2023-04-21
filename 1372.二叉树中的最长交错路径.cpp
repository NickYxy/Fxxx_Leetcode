/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
    /*
        采用深度优先遍历的方式，我们可以从顶向下访问到所有节点。并且遍历下一个子节点时，我们也能够知道子节点是属于父节点的左子树，还是右子树。
        所以我们可以为每个节点缓存两个值，一个l表示到达当前节点时，该节点为左子树时的路径数，一个r表示该节点为右子树时的到达路径。
        当然，一个节点要么是左子树，要么是右子树，所以l和r其中只有一个有值。
        那么在遍历该节点的子节点时，如果子节点是左子树，那么它的l值就是父节点的r值加1. 如果是右子树，就是父节点的l值加1.
    */

        dfs(root, 0, 0);
        return ans;
    }
    void dfs(TreeNode* root, int l, int r) {
        if (!root) return;
        ans = max(ans, max(l, r));

        dfs(root->left, r + 1, 0);
        dfs(root->right, 0, l +1);
    }
};
// @lc code=end

