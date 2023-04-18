/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int m = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i ++) sum += nums[i];
        int i = 0, j = k, max_sum = sum;
        while (i < m && j < m) {
            sum += (nums[j] - nums[i]);
            max_sum = max(max_sum, sum);
            j ++;
            i ++;
        }


        return (double)max_sum / k;
    }
};
// @lc code=end

