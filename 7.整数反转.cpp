/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            // 提前将可能超范围的步骤catch
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            ans = 10 * ans + x % 10;
            x /= 10;
        }
        return ans;
    }
};
// @lc code=end

