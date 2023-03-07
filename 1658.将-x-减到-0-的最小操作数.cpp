/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 0x3f大佬的理念，正难则反
        // 把这道题变成求最长连续子数组，使其sum = totalSum - x
        // tips: 窗口大小不固定的考虑双指针，窗口大小固定的考虑滑动窗口
        int n = nums.size();
        int total = 0;
        for (auto &num : nums) total += num;
        int target = total - x;
        if (target < 0) return -1;

        int sum = 0, left = 0, ans = -1;
        for (int right = 0; right < n; right ++) {
            sum += nums[right];
            while (sum > target)  sum -= nums[left++];
            if (sum == target) ans = max(ans, right - left + 1);
        }

        return ans < 0 ? -1 : n - ans;
    }
};
// @lc code=end

