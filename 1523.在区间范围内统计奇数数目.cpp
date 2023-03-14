/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        // 最大数和最小数都是偶数时，sum = (high - low)/2; 其他情况都是(high - low)/2 + 1;
        if (low % 2 == 0) low ++;
        if (low > high) return 0;
        return (high - low) / 2 + 1;
    }
};
// @lc code=end

