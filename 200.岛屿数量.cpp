/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0) return 0;
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans ++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        grid[x][y] = '2';
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < grid.size() && b>= 0 && b < grid[0].size() && grid[a][b] == '1') {
                dfs(grid, a, b);
            }
        }
    }
};
// @lc code=end

