/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, -1, -1};
        for (int x : nums) {
            // 每次记录下当前dp各个位置的最大值，赋值给abc
            // 然后再下一轮，进行max刷新当前值
            // 最后得到被3整除最大和，被3整除得1最大和，被3整除得2最大和
            int a = dp[0], b = dp[1], c = dp[2];
            if (a != -1) a += x, dp[a % 3] = max(dp[a % 3], a);
            if (b != -1) b += x, dp[b % 3] = max(dp[b % 3], b);
            if (c != -1) c += x, dp[c % 3] = max(dp[c % 3], c);
        }

        return dp[0];
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for (int a : nums) {
            vector<int> dp2 = {0, 0, 0};
            for (int i = 0; i < 3; ++ i) {
                dp2[(i + a) % 3] = max(dp[(i + a) % 3], dp[i] + a);
            }
            dp = dp2;
        }

        return dp[0];
    }
};
// @lc code=end

