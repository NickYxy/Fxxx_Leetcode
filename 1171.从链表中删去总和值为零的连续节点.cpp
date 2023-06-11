/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return nullptr;
        int sum = 0;
        for (auto t = head; t; t = t->next) {
            if ((sum += t->val) == 0) return removeZeroSumSublists(t->next);
        }
        head->next = removeZeroSumSublists(head->next);
        return head;
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;
        int sum = 0;
        for (auto t = dummy; t; t = t->next) { // 预设dummy为0，从dummy开始遍历
            // 就是为了防止[1, -1]这种情况，从dummy遍历的话，直接dummy->next = nullptr;
            sum += t->val;
            mp[sum] = t;
        }

        sum = 0;
        for (auto v = dummy; v; v = v->next) {
            sum += v->val;
            v->next = mp[sum]->next;
        }

        return dummy->next;
    }
};
// @lc code=end

