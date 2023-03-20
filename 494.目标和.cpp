/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // only + and -, 转换为一个正子集和一个负子集能满足数组sum == target
        // sum(P) - sum(N) = target
        // sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
        // 2 * sum(P) = target + sum(nums)
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || (sum + target) % 2 == 1) return 0;

        // 因此题目转化为01背包，也就是能组合成容量为newTarget的方式有多少种
        int newTarget = (sum + target) / 2;
        vector<int> dp(newTarget + 1);
        dp[0] = 1;

        for (auto &num : nums) {
            for (int i = newTarget; i >= num; i --) {
                dp[i] += dp[i - num];
            }
        }

        return dp[newTarget];
    }
};

class Solution {
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrace(nums, 0, 0, target);
        return ans;
    }

    void backtrace(vector<int>& nums, int sum, int start, int target) {
        if (target == sum && start == nums.size()) {
            ans ++;
            return;
        }
        if (start >= nums.size()) return;

        backtrace(nums, sum - nums[start], start + 1, target);
        backtrace(nums, sum + nums[start], start + 1, target);
    }
};
// @lc code=end

