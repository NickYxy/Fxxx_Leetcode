/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        dfs(n, 0, chessboard);
        return ans;
    }

    void dfs(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            ans ++;
            return;
        }

        for (int col = 0; col < n; ++ col) {
            if (isValid(row, col, chessboard, n)) {
                chessboard[row][col] = 'Q';
                dfs(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        for (int i = 0; i < row; ++ i) {
            if (chessboard[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; -- i, -- j) {
            if (chessboard[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; -- i, ++ j) {
            if (chessboard[i][j] == 'Q') return false;
        }

        return true;
    }
};
// @lc code=end

