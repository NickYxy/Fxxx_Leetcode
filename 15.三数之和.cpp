/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i ++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0) right --;
                else if (nums[i] + nums[left] + nums[right] < 0) left ++;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left ++;
                    while (left < right && nums[right] == nums[right - 1]) right --;
                    left ++;
                    right --;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

