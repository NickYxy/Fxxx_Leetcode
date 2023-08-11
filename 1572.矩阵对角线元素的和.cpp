/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; ++ i) {
            sum += mat[i][i];
            sum += mat[i][n - i - 1];
        }

        if (n % 2 == 0) return sum;
        else return sum - mat[n/2][n/2];
    }
};
// @lc code=end

