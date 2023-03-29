/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, 50000);
        int pre = -1;
        for (int i = 0; i < n; i ++) {
            if (s[i] == c) {
                pre = i;
                ans[i] = 0;
            } else if (pre != -1) ans[i] = abs(pre - i);
        }

        pre = -1;
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == c) {
                pre = i;
                ans[i] = 0;
            } else if (pre != -1) ans[i] = min(abs(pre - i), ans[i]);
        }

        return ans;
    }
};
// @lc code=end

