/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /**
            如果最右端的一部分已经排好序，这部分的每个数都比它左边的最大值要大，
            同理，如果最左端的一部分排好序，这每个数都比它右边的最小值小。
            所以我们从左往右遍历，如果i位置上的数比它左边部分最大值小，则这个数肯定要排序，
            就这样找到右端不用排序的部分，同理找到左端不用排序的部分，它们之间就是需要排序的部分
        **/
        int n = nums.size();
        if (n < 2) return 0;
        int l = 0, r = 0;
        int left_high = INT_MIN, right_low = INT_MAX;
        for (int i = 0; i < n; i ++) {
            if (left_high > nums[i]) {
                r = i;
            }
            left_high = max(left_high, nums[i]);
        }

        for (int i = n - 1; i >= 0; i --) {
            if (right_low < nums[i]) {
                l = i;
            }
            right_low = min(right_low, nums[i]);
        }

        return l == r ? 0 : r - l + 1;
    }
};
// @lc code=end

