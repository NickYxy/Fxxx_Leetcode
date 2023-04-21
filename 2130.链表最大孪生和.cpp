/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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
    int pairSum(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;
        auto cur = head, pre = cur->next;
        for (int i = 0; i < n / 2 - 1; ++ i) {
            auto tmp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }

        head->next = nullptr;
        int ans = 0;
        while (cur && pre) {
            ans = max(cur->val + pre->val, ans);
            cur = cur->next;
            pre = pre->next;
        }

        return ans;
    }
};
// @lc code=end

