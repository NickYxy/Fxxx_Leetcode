/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

class Solution {
public:
    bool isValid(string s) {
        // 和左右括号的思路一样，顺序入栈，遇到abc消掉
        // 如果当前值为a，直接入栈
        // 如果当前值为b，那么如果栈为空或者栈顶元素不是a，可以直接返回false
        // 如果当前值为c, 那么如果栈为空或者栈顶元素不是b, 可以直接返回false
        stack<char> stk;
        for (char& ch : s) {
            if (ch == 'b' && (stk.empty() || (!stk.empty() && stk.top() != 'a'))) return false;
            else if (ch == 'c' && (stk.empty() || (!stk.empty() && stk.top() != 'b'))) return false;
            stk.push(ch);
            if (ch == 'c') {
                stk.pop();
                stk.pop();
                stk.pop();
            }
        }

        return stk.empty();
    }
};

class Solution:
    def isValid(self, s: str) -> bool:
        while s != "" and 'abc' in s:
            s = s.replace('abc', '')
        return s == ""
// @lc code=end

