/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    // 二叉搜索树的中序遍历序列是单调递增的。 利用二叉树的迭代方式的中序遍历，保存左子链，从而使用O(h)的内存。
    vector<TreeNode* > st;
    BSTIterator(TreeNode* root) {
        while (root) {
            st.push_back(root);
            root = root->left;
        }
    }

    int next() {
        auto t = st.back();
        st.pop_back();
        int v = t->val;
        t = t->right;
        while (t) {
            st.push_back(t);
            t = t->left;
        }

        return v;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

