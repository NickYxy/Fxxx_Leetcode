/*
 * @lc app=leetcode.cn id=822 lang=cpp
 *
 * [822] 翻转卡片游戏
 */

// @lc code=start
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> S;
        int n = fronts.size(), ans = INT_MAX;
        for (int i = 0; i < n; ++ i) {
            if (fronts[i] == backs[i]) S.emplace(fronts[i]);
        }

        for (int i = 0; i < n; ++ i) {
            int x = fronts[i], y = backs[i];
            if (!S.count(x)) {
                ans = min(ans, x);
            }
            if (!S.count(y)) {
                ans = min(ans, y);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

