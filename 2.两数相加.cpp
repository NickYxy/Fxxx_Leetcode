/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        auto dummy = new ListNode(-1);
        auto head = dummy;
        int carry = 0;

        while (carry || l1 || l2) {
            int a, b;
            if (l1) a = l1->val; else a = 0;
            if (l2) b = l2->val; else b = 0;
            int sum = a + b + carry;
            head->next = new ListNode(sum % 10);
            carry = sum / 10;
            head = head->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }


        return dummy->next;
    }
};
// @lc code=end

