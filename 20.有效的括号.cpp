/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for (auto ch : s) {
            if (ch == '(') stk.push(')');
            else if (ch == '[') stk.push(']');
            else if (ch == '{') stk.push('}');
            else if (stk.empty() || ch != stk.top()) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};
// @lc code=end

