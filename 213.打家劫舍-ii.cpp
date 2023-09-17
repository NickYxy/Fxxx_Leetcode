/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return  max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    int robRange(vector<int>&nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++ i) {
            int temp = second;
            second = max(first +nums[i], second);
            first = temp;
        }

        return second;
    }
};
// @lc code=end

