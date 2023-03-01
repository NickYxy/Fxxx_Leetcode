/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 0; i < n; i ++) {
            if (cur > 0) cur += nums[i];
            else cur = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

