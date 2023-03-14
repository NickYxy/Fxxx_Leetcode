/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 由题意可以得知，我们可以将石头堆分成两部分，然后取他们差的最小值即可；
        // 这就转移为01背包问题，我们假设背包最多能装sum/2的石头，然后尽量让最大值靠近sum/2
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum / 2 + 1);
        for (int i = 0; i < n; i ++) {
            for (int j = sum / 2; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[sum / 2];
    }
};
// @lc code=end

