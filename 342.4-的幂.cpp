/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        cout << (4 / 4);
        return n > 0 && ((n&(n-1)) == 0) && n % 3 == 1;
    }
};
// @lc code=end

