/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, n = s.size();
        int j = 0;
        while (j < n) {
            int cnt_z = 0, cnt_one = 0;
            while (j < n && s[j] != '0') j ++;
            while (j < n && s[j] == '0') j ++, cnt_z ++;
            while (j < n && s[j] == '1') j ++, cnt_one ++;
            ans = max(ans, 2 * min(cnt_one, cnt_z));
        }

        return ans;
    }
};
// @lc code=end

