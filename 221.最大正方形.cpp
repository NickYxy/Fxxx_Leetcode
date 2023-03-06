/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /**
        dp[i][j]表示以第i行第j列为右下角所能构成的最大正方形边长, 则递推式为:
        dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        当我们判断以某个点为正方形右下角时最大的正方形时，那它的上方，左方和左上方三个点也一定是某个正方形的右下角，
        否则该点为右下角的正方形最大就是它自己了。这是定性的判断，那具体的最大正方形边长呢？
        我们知道，该点为右下角的正方形的最大边长，最多比它的上方，左方和左上方为右下角的正方形的边长多1，
        最好的情况是是它的上方，左方和左上方为右下角的正方形的大小都一样的，这样加上该点就可以构成一个更大的正方形。
        但如果它的上方，左方和左上方为右下角的正方形的大小不一样，合起来就会缺了某个角落，这时候只能取那三个正方形中最小的正方形的边长加1了。
        假设dpi表示以i,j为右下角的正方形的最大边长，则有 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
        当然，如果这个点在原矩阵中本身就是0的话，那dp[i]肯定就是0了。
        **/
        int m = matrix.size();
        if(m < 1) return 0;
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans*ans;
    }
};
// @lc code=end

