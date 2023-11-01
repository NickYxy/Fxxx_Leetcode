/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0 && k >= 0) {
            if (nums1[i] <= nums2[j]) nums1[k--] = nums2[j--];
            else if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        }

        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
// @lc code=end

