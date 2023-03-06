/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /**
        dp[i][j]代表以A[i-1]与B[j-1]结尾的公共字串的长度,公共字串必须以A[i-1]，B[j-1]结束，
        即当A[i-1] == B[j-1]时，dp[i][j] = dp[i-1][j-1] + 1;
        当A[i-1] != B[j-1]时，以A[i-1]和B[j-1]结尾的公共字串长度为0,dp[i][j] = 0。
        输出最大的公共字串的长度即为最长重复字串。
        如果定义 dp[i][j]为 以下标i为结尾的A，和以下标j 为结尾的B，
        那么 第一行和第一列毕竟要经行初始化，如果nums1[i] 与 nums2[0] 相同的话，
        对应的 dp[i][0]就要初始为1， 因为此时最长重复子数组为1。
        nums2[j] 与 nums1[0]相同的话，同理。
        **/
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

