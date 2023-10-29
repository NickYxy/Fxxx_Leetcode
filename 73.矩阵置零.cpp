/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 直观 - 为0的元素横竖轴标记下来，然后全部置为0
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> mark;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == 0) mark.push_back(make_pair(i, j));
            }
        }

        for (auto& p : mark) {
            for (int i = 0; i < m; ++ i) matrix[i][p.second] = 0;
            for (int i = 0; i < n; ++ i) matrix[p.first][i] = 0;
        }

        return;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 空间O（1），用两个变量标记
        int m = matrix.size(), n = matrix[0].size();
        bool row0 =false, col0 = false;
        for (int i = 0; i < m; i ++ ) {
            if (matrix[i][0] == 0) row0 = true;
        }

        for (int i = 0; i < n; i ++ ) {
            if (matrix[0][i] == 0) col0 = true;
        }

        for (int i = 1; i < m; i ++ )
            for (int j = 1; j < n; j ++ ) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }

        for (int i = 1; i < m; i ++ )
            for (int j = 1; j < n; j ++ ) {
                if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }

        if (col0) {
            for (int i = 0; i < n; i ++ ) matrix[0][i] = 0;
        }

        if (row0) {
            for (int i = 0; i < m; i ++ ) matrix[i][0] = 0;
        }

    }
};
// @lc code=end

