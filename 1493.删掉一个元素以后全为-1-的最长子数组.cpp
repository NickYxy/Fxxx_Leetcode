/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, k = 1;
        int n = nums.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (nums[j] == 0) k --;
            j ++;

            while (k < 0) {
                if (nums[i] == 0) k++;
                i ++;
            }
            ans = max(ans, j - i - 1);
        }

        return ans;
    }
};
// @lc code=end

