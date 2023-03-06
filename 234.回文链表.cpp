/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        auto sc = head;
        while(sc) {
            st.push(sc->val);
            sc = sc->next;
        }

        auto cur = head;
        while(cur) {
            auto tmp = st.top();
            if (cur->val == tmp) {
                st.pop();
                cur = cur->next;
            } else return false;
        }

        return st.empty();
    }
};
// @lc code=end

