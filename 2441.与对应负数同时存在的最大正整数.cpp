/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 *
 * [2441] 与对应负数同时存在的最大正整数
 */

// @lc code=start
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = INT_MIN;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++ i) {
            mp[nums[i]] ++;
            if (mp.count(-nums[i]) > 0) ans = max(ans, abs(nums[i]));
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
// @lc code=end

