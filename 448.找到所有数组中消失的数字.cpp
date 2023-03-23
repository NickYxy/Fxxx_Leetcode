/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字。
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }

        for (int i = 0; i < n; i ++) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }

        return ans;
    }
};
// @lc code=end

