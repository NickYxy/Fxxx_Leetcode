/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto pre = dummy;
        for (int i = 0; i < left - 1; i ++) {
            pre = pre->next;
        }

        auto start = pre->next, cur = start->next;
        for (int i = 0; i < right - left; i ++) {
            auto tmp = cur->next;
            cur->next = start;
            start = cur;
            cur = tmp;
        }
        pre->next->next = cur;
        pre->next = start;
        return dummy->next;
    }
};
// @lc code=end

