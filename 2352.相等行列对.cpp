/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 *
 * [2352] 相等行列对
 */

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m != n) return 0;

        map<vector<int>, int> mp;
        for (int i = 0; i < m; ++ i) {
            mp[grid[i]] ++;
        }

        int ans = 0;
        for (int i = 0; i < m; ++ i) {
            vector<int> col;
            for (int j = 0; j < n; ++ j)
                col.push_back(grid[j][i]);
            if (mp.count(col)) ans += mp[col];
        }

        return ans;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // 把矩阵转置一下，然后直接进行比较
        int ans = 0;
        vector<vector<int>> grid2(grid.size(), vector<int>(grid.size()));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                grid2[i][j] = grid[j][i];
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (grid[i] == grid2[j])
                    ans++;
        return ans;
    }
};
// @lc code=end

