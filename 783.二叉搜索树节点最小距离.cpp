/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    vector<int> tmp;
    int minDiffInBST(TreeNode* root) {
        traversal(root);
        int ans = INT_MAX;
        for (int i = 1; i < tmp.size(); i ++) {
            ans = min(ans, tmp[i] - tmp[i - 1]);
        }

        return ans;
    }

    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        tmp.push_back(root->val);
        traversal(root->right);
    }
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur || st.size()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre) {
                    ans = min(ans, abs(cur->val - pre->val));
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return ans;

        return ans;
    }
};
// @lc code=end

