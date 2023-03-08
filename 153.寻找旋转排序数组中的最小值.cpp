/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        /**
        为什么不用 mid 和最左边的值比较？ 因为这是一个旋转之后的递增序列，用 mid 和 left 比，mid 比 left 的值大，
        也无法证明 最小值在 mid 的左边或者右边。
        但是用 mid 和 right 比，mid 大于 right，说明最小值在 mid 右边（不包含 mid，因为 right 就比 mid 小） mid 小于 right，
        说明右边是有序的，并且最小的就是 mid，最小值在 mid 的左边（包含mid）
        **/
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (r + l) >> 1;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
// @lc code=end

