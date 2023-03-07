/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
        return nums;
    }

    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int i = l - 1, j = r + 1;
        int pivot = nums[(l + r) >> 1];
        while (i < j) {
            do i ++; while (nums[i] < pivot);
            do j --; while (nums[j] > pivot);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    }
};
// @lc code=end

