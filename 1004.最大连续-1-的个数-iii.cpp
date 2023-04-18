/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 翻译过来就是求一共有k个0所能达到的最长的区间
        int ans = 0, m = nums.size();
        int i = 0, j = 0;
        while (i < m && j < m) {
            if (nums[j] == 0) k --;
            j ++;

            while (k < 0) {
                if (nums[i] == 0) k ++;
                i ++;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};
// @lc code=end

