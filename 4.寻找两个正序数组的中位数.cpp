/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);// 保证短的数组在前面

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int mid1 = 0, mid2 = 0; // mid1是前半部分的最大值，mid2是后半部分的最小值

        while (left <= right) {
            int i = (left + right) / 2; // 前半部分的长度
            int j = (m + n + 1) / 2 - i; // 后半部分的长度

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]); // 取极小值，可以避免对前半段取最大值造成影响
            int nums_i = (i == m ? INT_MAX : nums1[i]); // 取极大值，可以避免对后半段取最小值造成影响
            int nums_jm1 = (j == 0 ? INT_MIN: nums2[j - 1]);
            int nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j) {
                mid1 = max(nums_im1, nums_jm1);
                mid2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (mid1 + mid2) / 2.0 : mid1;
    }
};
// @lc code=end

