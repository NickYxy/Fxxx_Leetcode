/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto head = new ListNode(0);
        auto cmp = [](ListNode* const&a, ListNode* const &b){return a->val > b->val;};

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (auto &list : lists) if (list) q.push(list);
        auto p = head;
        while (q.size()) {
            p->next = q.top();
            p = p->next;
            q.pop();
            if (p->next) q.push(p->next);
        }
        return head->next;
    }
};
// @lc code=end

