/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先转置再左右镜像对称
        int m = matrix.size();
        for (int i = 0; i < m; i ++) {
            for (int j = i + 1; j < m; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m / 2; j++) {
                swap(matrix[i][j], matrix[i][m - j - 1]);
            }
        }

        return;
    }
};
// @lc code=end

