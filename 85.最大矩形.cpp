/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 暴力循环，找到每个元素左边有多少个连续1，然后高度上迭代
        int m = matrix.size();
        if (m == 0) return 0;

        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == '1') {
                    left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == '0') continue;

                int width = left[i][j];
                int area = width;
                for (int k = i - 1; k >= 0; -- k) {
                    width = min(width, left[k][j]);
                    area = max(area, width * (i - k + 1));
                }
                res = max(res, area);
            }
        }

        return res;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;

        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == '1') {
                    left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                }
            }
        }

        int res = 0;
        for (int j = 0; j < n ; ++ j) {
            vector<int> up(m, 0), down(m, 0);
            stack<int> stk;

            for (int i = 0; i < m; ++ i) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; ++ i) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                res = max(res, area);
            }
        }
        return res;
    }
};
// @lc code=end

