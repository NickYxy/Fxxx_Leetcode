/*
 * @lc app=leetcode.cn id=2258 lang=cpp
 *
 * [2258] 逃离火灾
 */

// @lc code=start
class Solution {
private:
    int n, m;
    const int inf = 1e9;
    vector<vector<int>> fire;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool check(int wt, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        if (fire[0][0] <= wt) return false;
        vector<vector<int>> dis(n, vector<int>(m, inf));
        q.push({0, 0});
        dis[0][0] = 0;
        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++ k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 2) continue;
                if (dis[nx][ny] != inf) continue;
                if (nx == n - 1 && ny == m - 1 && dis[x][y] + 1 + wt <= fire[nx][ny]) return true;
                if (dis[x][y] + 1 + wt >= fire[nx][ny]) continue; // 走不过去，火已经烧了
                dis[nx][ny]  = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return false;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        // 先预处理火到每个位置的最短时间以及人到每个位置的最短时间，再二分+bfs计算可行的停留时间
        //先多源bfs确定每个格子着火的时间.
        n = grid.size(), m = grid[0].size();
        fire = vector<vector<int>>(n, vector<int>(m, inf));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++ k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 2) continue;
                if (fire[nx][ny] != inf) continue;
                fire[nx][ny] = fire[x][y] + 1;
                q.push({nx, ny});
            }
        }

        int l = 0, r = n * m, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, grid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        return ans == n * m ? 1e9 : ans;
    }
};
// @lc code=end

