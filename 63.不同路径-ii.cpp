/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (!m || !n) return 1;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<int> f(n);
        f[0] = (obstacleGrid[0][0] == 0);

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j >= 1 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};
class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    int dx[2] = {0, 1}, dy[2] = {1, 0};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]) return 0;

        memo.resize(m, vector<int>(n));

        return dfs(obstacleGrid, 0, 0);
    }

    int dfs(vector<vector<int>>& obstacleGrid, int a, int b) {
        if (memo[a][b] != 0) return memo[a][b];
        if (a == m - 1 && b == n - 1) {
            memo[a][b] = 1;
            return 1;
        }

        int total = 0;
        for (int i = 0; i < 2; ++ i) {
            int x = a + dx[i], y = b + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && obstacleGrid[x][y] == 0) {
                total += dfs(obstacleGrid, x, y);
            }
        }
        memo[a][b] = total;
        return memo[a][b];
    }
};
// @lc code=end

