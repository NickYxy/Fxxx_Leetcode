/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 由于是子序列，记录之前最长的up和down，然后遇到down就加上之前的up，遇到up就加上之前的down
        int n = nums.size();
        int up = 1, down = 1;
        for (int i = 1; i < n; ++ i) {
            if (nums[i] > nums[i - 1]) up = down + 1;
            if (nums[i] < nums[i - 1]) down = up + 1;
        }

        return max(up, down);
    }
};
// @lc code=end

