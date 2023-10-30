/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int index = 2;
        for (int i = 2; i < n; ++ i) {
            if (nums[index - 2] != nums[i]) {
                nums[index] = nums[i];
                index ++;
            }
        }

        return index;
    }
};
// @lc code=end

