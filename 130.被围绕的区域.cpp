/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        if (m == 1 || n == 1) return;

        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board);
        }

        for (int i = 0; i < n; i ++) {
            if (board[0][i] == 'O') dfs(0, i, board);
            if (board[m - 1][i] == 'O') dfs(m - 1, i, board);
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
        return;
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '1';
        int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size() && board[a][b] == 'O') {
                dfs(a, b, board);
            }
        }
        return;
    }
};
// @lc code=end

