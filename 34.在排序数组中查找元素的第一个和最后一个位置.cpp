/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 利用二分思想先找其左边界，再找其右边界即可，
        // 注意找左边界的时候，由右侧逼近；找右边界的时候，由左侧逼近，即可。
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        if (nums[right] != target) return {-1, -1};
        int l = right;
        left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }

        return {l, right};
    }
};
// @lc code=end

