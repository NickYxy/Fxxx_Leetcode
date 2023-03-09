/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int num = 1, j = 0;
        while (num <= n * n) {
            for (int i = j; i < n - j; i ++) {
                ans[j][i] = num ++;
            }
            for (int i = j + 1; i < n - j; i ++) {
                ans[i][n - j - 1] = num ++;
            }
            for (int i = n - j - 2; i >= j; i --) {
                ans[n - j - 1][i] = num ++;
            }
            for (int i = n - j - 2; i > j; i --) {
                ans[i][j] = num ++;
            }
            j ++;
        }

        return ans;
    }
};
// @lc code=end

