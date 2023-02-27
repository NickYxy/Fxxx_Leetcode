/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>& nums, int start) {
            int cnt = 0;
            for (int i = start; i < nums.size(); i += 2) {
                int t = nums[i];
                if ((i - 1) >= 0) t = min(t, nums[i - 1] - 1);
                if ((i + 1) < nums.size()) t = min(t, nums[i + 1] - 1);
                cnt += nums[i] - t;
            }
            return cnt;
        }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(helper(nums, 0), helper(nums, 1));
    }
};

// @lc code=end

