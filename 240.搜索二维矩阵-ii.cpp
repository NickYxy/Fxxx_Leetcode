/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (!m || !n) return false;
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int i = 0, j = n - 1;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) j --;
            else i ++;
        }

        return false;
    }
};
// @lc code=end

