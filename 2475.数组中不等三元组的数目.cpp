/*
 * @lc app=leetcode.cn id=2475 lang=cpp
 *
 * [2475] 数组中不等三元组的数目
 */

// @lc code=start
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; ++ i) {
            for (int j = i + 1; j < n - 1; ++ j) {
                if (nums[i] == nums[j]) continue;
                else {
                    for (int k = j + 1; k < n; ++ k) {
                        if (nums[j] == nums[k]) continue;
                        else if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) ans ++;
                }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

