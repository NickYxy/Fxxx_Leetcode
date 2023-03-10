/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        auto slow = head, fast = head;
        while (head) {
            if (!fast || !fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        auto third = head;
        while (third != slow) {
            third = third->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

