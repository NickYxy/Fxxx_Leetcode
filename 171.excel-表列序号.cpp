/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int n = columnTitle.size();
        for (int i = 0; i < n; i ++) {
            int temp = columnTitle[i] - 'A' + 1;
            ans = 26 * ans + temp;
        }

        return ans;
    }
};
// @lc code=end

