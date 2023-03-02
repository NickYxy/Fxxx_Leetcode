/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto pre = dummy, cur = pre->next;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                int x = cur->val;
                while (cur && cur->val == x) cur = cur->next;
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

