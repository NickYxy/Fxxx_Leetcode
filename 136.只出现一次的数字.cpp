/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 相同的两个数做异或，a ^ a = 0
        // 任何数和0做异或都等于它本身
        int ans = 0;
        for (auto& num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
// @lc code=end

