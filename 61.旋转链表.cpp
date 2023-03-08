/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // 特例一定要判断
        int len = 1;
        auto node = head;
        while (node->next) {
            node = node->next;
            len ++;
        }
        k = (k % len);
        if (k == 0) return head; // 保持不变，也要剪枝做判断
        auto pre = head;
        for (int i = 0; i < (len - k - 1); i ++) {
            pre = pre->next;
        }
        auto cur = pre->next;
        pre->next = nullptr;
        node->next = head;
        return cur;
    }
};
// @lc code=end

