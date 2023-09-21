/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; ++ i) {
            if (mp.count(target - nums[i])) {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};
// @lc code=end

