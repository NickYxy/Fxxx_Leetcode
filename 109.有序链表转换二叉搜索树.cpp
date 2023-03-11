/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        // 快慢指针找到中点，中点作为root，左边的为左子树，右边的为右子树
        // 可以保证高度平衡，且符合左小右大的二叉树特点
        auto fast = head, slow = head;
        auto pre = new ListNode(INT_MIN);
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        // 分割slow左边的链表用来递归生成左子树，同理右边的用来递归生成右子树
        // 1->2->3->null  slow(root)  4->5->6->null;
        pre->next = nullptr;
        auto rightList = slow->next;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(rightList);
        return root;
    }
};
// @lc code=end

