/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 不同的组合数，为什么外围是物品，内层是背包，就不会重复呢？
        // 因为如果外层是背包，那么背包从小到大，会多次重复计算
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i ++) {
            for (int j = coins[i]; j <= amount; j ++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

