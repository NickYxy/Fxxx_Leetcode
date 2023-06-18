/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 0 && dfs(grid, i, j)) {
                    ans ++;
                }
            }
        }

        return ans;
    }

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) return false;
        grid[i][j] = 1;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        bool f = true;
        for (int k = 0; k < 4; ++ k) {
            int a = i + dx[k], b = j + dy[k];
            if (grid[a][b] == 1) continue;
            if (grid[a][b] == 0) f &= dfs(grid, a, b);
        }
        return f;
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        bool closed = true;
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    closed = true;
                    while (q.size()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) closed = false;

                        for (int k = 0; k < 4; ++ k) {
                            int a = x + dx[k], b = y + dy[k];
                            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 0) {
                                grid[a][b] = 1;
                                q.push(make_pair(a, b));
                            }
                        }
                    }
                    if (closed) ans ++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

