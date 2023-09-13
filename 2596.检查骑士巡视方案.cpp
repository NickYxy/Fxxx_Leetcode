/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0) return false;
        vector<pair<int, int>> t(n * n);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                t[grid[i][j]] = {i, j};
            }
        }

        for (int i = 1; i < n * n; ++ i) {
            auto [x1, y1] = t[i];
            auto [x0, y0] = t[i - 1];
            int w = abs(x1 - x0), h = abs(y1 - y0);
            if ((!(w==1 && h==2) && !(w==2 && h==1))) return false;
        }

        return true;
    }
};
// @lc code=end

