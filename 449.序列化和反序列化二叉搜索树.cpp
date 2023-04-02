/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int idx = 0;
    int n;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "null";
        }
        string ans = "";
        ans += to_string(root->val) + ",";
        ans += serialize(root->left) + ",";
        ans += serialize(root->right);
        return ans;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        n = data.size();
        if(idx >= n) {
            return nullptr;
        }
        string num = "";
        while(idx < n && data[idx] != ',') {
            num += data[idx];
            ++idx;
        }
        ++idx;    // 跳过逗号
        if(num == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(num));
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

