/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        int ans = INT_MAX;
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                } else if (j == n - 1) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                } else {
                    matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i - 1][j + 1]));
                }
                if (i == n - 1) ans = min(ans, matrix[i][j]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++ i) dp[0][i] = matrix[0][i];
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int mn = dp[i - 1][j];
                if (j >= 1) mn = min(mn, dp[i - 1][j - 1]);
                if (j < n - 1) mn = min(mn, dp[i - 1][j + 1]);
                dp[i][j] = matrix[i][j] + mn;
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end

