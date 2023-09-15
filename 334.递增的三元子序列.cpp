/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // 时间复杂度为 O(n) ，空间复杂度为 O(1)
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] > second) return true;
            else if (nums[i] > first) second = nums[i];
            else first = nums[i];
        }

        return false;
    }
};
// @lc code=end

