/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        auto a = headA, b = headB;
        while (a != b) {
            if (a) a = a->next;
            else a = headB;
            if (b) b = b->next;
            else b = headA;
        }
        return a;
    }
};
// @lc code=end

