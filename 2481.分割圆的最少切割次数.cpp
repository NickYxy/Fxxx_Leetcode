/*
 * @lc app=leetcode.cn id=2481 lang=cpp
 *
 * [2481] 分割圆的最少切割次数
 */

// @lc code=start
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return n / 2;
        else return n;
    }
};
// @lc code=end

