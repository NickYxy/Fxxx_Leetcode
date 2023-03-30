/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

// @lc code=start
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end());
        for (int i = 1; i < points.size(); i ++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }

        return ans;
    }
};
// @lc code=end

