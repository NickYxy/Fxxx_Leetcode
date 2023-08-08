/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // [i, j]区间的和等于prefixSum[j] - prefixSum[i - 1]，如果求最值的话有两种情况，
        // 以i结尾区间最小值：prefixSum[i] - max(prefixSum[0:(i -1)])
        // 以i结尾区间最大值：prefixSum[i] - min(prefixSum[0:(i -1)]) 求绝对值最大就是求最值，所以记录三个变量，前缀和，前缀和最大值和最小值，就能得出答案了
        int total = 0, mx = 0, mi = 0;
        for (int& num : nums) {
            total += num;
            if (total > mx) mx = total;
            else if (total < mi) mi = total;
        }
        return mx - mi;
    }
};
// @lc code=end

