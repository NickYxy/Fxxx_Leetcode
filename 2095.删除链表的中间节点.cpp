/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        auto slow = head, fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;
        int k = n / 2;
        auto pre = head;
        auto ans = pre->next->next;
        for (int i = 0; i < k - 1; ++ i) {
            pre = pre->next;
            if (ans) ans = ans->next;
        }
        if (!ans){
            head->next = nullptr;
            return head;
        }
        pre->next = ans;

        return head;
    }
};
// @lc code=end

