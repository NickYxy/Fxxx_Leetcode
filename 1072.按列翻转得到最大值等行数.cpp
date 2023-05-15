/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 */

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        map<vector<int>, int> mp;
        for (int i = 0; i < m; ++ i) {
            mp[matrix[i]] ++;
            for (int j = 0; j < n; ++ j) {
                matrix[i][j] = !matrix[i][j];
            }
            mp[matrix[i]] ++;
        }

        for (auto& [k, v] : mp) res = max(res, v);

        return res;
    }
};
// @lc code=end

