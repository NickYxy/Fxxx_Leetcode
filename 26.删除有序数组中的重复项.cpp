/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int i = 0, j = 1;
        while (j < n) {
            if (nums[i] == nums[j]) {
                j ++;
            } else {
                i ++;
                nums[i] = nums[j];
                j ++;
            }
        }
        return i + 1;
    }
};
// @lc code=end

