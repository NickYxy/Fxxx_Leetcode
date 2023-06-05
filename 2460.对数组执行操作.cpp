/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 *
 * [2460] 对数组执行操作
 */

// @lc code=start
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++ i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        vector<int> ans(n);
        int t = 0;
        for (int i = 0; i < n; ++ i) {
            if (nums[i] != 0) {
                ans[t ++] = nums[i];
            }
        }

        return ans;
    }
};
// @lc code=end

