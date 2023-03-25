/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        // 每当n往右移动一位，res就向左移动一位
        for (int i = 0; i < 32; i ++) {
            ans = (n & 1) | (ans << 1);
            n >>= 1;
        }

        return ans;
    }
};
// @lc code=end

