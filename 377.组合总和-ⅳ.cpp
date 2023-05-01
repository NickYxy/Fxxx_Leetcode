/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> mp;
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums, 0, target);
    }

    int dfs(vector<int>& nums, int total, int target) {
        if (total == target) return 1;
        if (total > target) return 0;
        if (mp.count(total)) return mp[total];
        int ans = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            ans += dfs(nums, total + nums[i], target);
        }
        mp[total] = ans;
        return ans;
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

