/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 *
 * [2544] 交替数字和
 */

// @lc code=start
class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        while (n) {
            ans += sign * (n % 10);
            n /= 10;
            sign = -sign;
        }

        return sign == 1 ? -ans : ans;
    }
};
// @lc code=end

