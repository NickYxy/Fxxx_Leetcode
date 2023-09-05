/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */

// @lc code=start
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int mi1 = 999, mi2 = 999, ans = 999;
        for (int i = 0; i < m; i ++) {
            mi1 = min(mi1, nums1[i]);
            for (int j = 0; j < n; j ++) {
                mi2 = min(mi2, nums2[j]);
                if (nums1[i] == nums2[j]) ans = min(ans, nums1[i]);
            }
        }
        if (ans <= 9) return ans;
        else {
            ans = min(mi1, mi2) * 10 + max(mi1, mi2);
            return ans;
        }
    }
};
// @lc code=end

