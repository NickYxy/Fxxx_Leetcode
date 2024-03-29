/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return false;
        if (n == 1) return nums[0] == target;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
                ++l;
                --r;
            }
            else if (nums[mid] >= nums[l]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else l = mid + 1;

            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else r = mid - 1;
            }
        }

        return false;
    }
};
// @lc code=end

