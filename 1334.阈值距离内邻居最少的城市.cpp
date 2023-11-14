/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> w(n, vector<int>(n, INT_MAX / 2)); // 防止加法溢出
        for (auto &e: edges) {
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt;
        }

        auto f = move(w);
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }

        int ans = 0;
        int min_cnt = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && f[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= min_cnt) { // 相等时取最大的 i
                min_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end

