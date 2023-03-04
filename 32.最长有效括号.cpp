/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int ans = 0;
        stack<int> stk;
        for (int i = 0, start = -1; i < n; i ++) {
            if (s[i] == '(') stk.push(i);
            else {
                if (stk.size()) {
                    stk.pop();
                    if (stk.size()) {
                        ans = max(ans, i - stk.top());
                    } else {
                        ans = max(ans, i - start);
                    }
                } else {
                    start = i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

