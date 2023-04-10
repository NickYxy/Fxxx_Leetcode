/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> tmp;
        for (auto cur = head; cur; cur = cur->next) tmp.emplace_back(cur->val);

        int n = tmp.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (stk.size() && tmp[i] > tmp[stk.top()]) {
                ans[stk.top()] = tmp[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

