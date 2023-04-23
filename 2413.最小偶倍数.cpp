/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 *
 * [2413] 最小偶倍数
 */

// @lc code=start
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n << (n & 1);
    }
};

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) return n;
        else return 2 * n;
    }
};
// @lc code=end

