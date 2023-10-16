/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) return nums;

        int x = 0;
        for (auto& num : nums) x ^= num;
        int idx = (x == INT_MIN ? x : x &(-x));
        int l = 0, r = 0;
        for (auto& num : nums) {
            if ((num & idx) != 0) l ^= num;
            else r ^= num;
        }

        return {l, r};
    }
};
// @lc code=end

