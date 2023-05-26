/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || n == 0) return -1;
        int directionX[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int directionY[8] = {0, 1, 0, -1, 1, -1, -1, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        int path = 1;
        while (q.size()) {
            int siz = q.size();

            while (siz --) {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;

                if (x == n - 1 && y == n - 1) return path;

                for (int i = 0; i < 8; ++ i) {
                    int a = x + directionX[i], b = y + directionY[i];
                    if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 0) {
                        q.push({a, b});
                        grid[a][b] = 1;
                    }
                }
            }
            path ++;
        }

        return -1;
    }
};
// @lc code=end

