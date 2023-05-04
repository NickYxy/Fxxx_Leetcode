/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> PII;
    int cnt = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<PII> q; // bfs必备队列
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (q.size()) {
            int t = q.size();
            for (int i = 0; i < t; ++ i) { // 对队列里的所有烂橘子进行广度向周边腐蚀
                PII temp = q.front();
                q.pop();

                for (int j = 0; j < 4; ++ j) {
                    int a = temp.first + dx[j], b = temp.second + dy[j];
                    if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1) {
                        grid[a][b] = 2; // 遇到新鲜的腐蚀掉并且加入下一轮的队列里
                        q.push({a, b});
                    }
                }
            }

            if (q.size()) cnt ++; // 压入了一批新的橘子
        }

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};
// @lc code=end

