/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        s[0] = 0;
        // 求前缀和数组，然后让两个数组索引对齐，方便下面的边界计算
        for (int i = 1; i <= n; ++ i) s[i] = s[i - 1] + nums[i - 1];

        // [0, 6, 11, 13, 15, 20, 21, 30, 34]
        int ans = 0, maxSumA = 0, maxSumB = 0;
        for (int i = firstLen + secondLen; i <= n; ++ i) {
            // maxSumA,即左边为first的时候，first的最大值；maxSumB，当左边为second的时候，second的最大值
            maxSumA = max(maxSumA, s[i - secondLen] - s[i - secondLen - firstLen]);
            maxSumB = max(maxSumB, s[i - firstLen] - s[i - firstLen - secondLen]);
            ans = max(ans, max(maxSumA + s[i] - s[i - secondLen], maxSumB + s[i] - s[i - firstLen])); // 左1右2、左2右1
        }

        return ans;
    }
};
// @lc code=end

