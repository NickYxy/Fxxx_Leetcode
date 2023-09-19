/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
// 见到最大的最小或者最小的最大，必定是二分
// 定义f[i]为从nums[0]到nums[i]所能偷得最大值的不大于mx的最多房间数
// 如果大于k表示答案最多为mx，否则答案必须超过mx，因为最大值金额越大能偷得越多，最大值金额越少能偷得越少
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(nums, k, mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }

    bool check(vector<int>& nums, int k, int mx) {
        int f0 = 0, f1 = 0;
        for (auto& x : nums) {
            if (x > mx) {
                f0 = f1;
            } else {
                int temp = f1;
                f1 = max(f1, f0 + 1);
                f0 = temp;
            }
        }

        return f1 >= k;
    }
};
// @lc code=end

