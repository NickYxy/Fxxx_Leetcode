/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        //dp,dp[i][j]代表以nums[i]结尾，公差为j的最长子序列
        //dp[i][j]=max(dp[k][j])+1,where nums[i]-nums[k]=j
        //j:-500~500,共1001个，添加偏移量500保证非负
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }
};
// @lc code=end

