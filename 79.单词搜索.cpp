/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y) {
        if (board[x][y] != word[index]) return false;
        if (index == word.size() - 1) return true;

        auto t = board[x][y]; // 提前记下之前的值，恢复现场的时候要用
        board[x][y] = '0';
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k ++) {
            int a = x + dx[k], b = y + dy[k];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '0') continue;
            if (dfs(board, word, index + 1, a, b)) return true;;
        }
        board[x][y] = t; // 撤销修改，恢复现场
        return false;
    }



    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }
};
// @lc code=end

