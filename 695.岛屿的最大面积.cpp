/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int ans = 0, cur = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    cur = 1;
                    dfs(grid, i, j);
                    ans = max(ans, cur);
                    cur = 0;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 2;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k ++) {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == 1) {
                cur ++;
                dfs(grid, a, b);
            }
        }
    }
};
// @lc code=end

