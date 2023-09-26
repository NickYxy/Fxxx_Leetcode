/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x < 10) return true;
        if (x % 10 == 0) return false;

        long temp = 0, cur = x;
        while (x) {
            int mod = x % 10;
            temp =  temp * 10 + mod;
            x /= 10;
        }

        return temp == cur;
    }
};
// @lc code=end

