/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        // 思路一分钟，边界处理一小时
        for (auto& s : asteroids) {
            while (ans.size() && s < 0 && ans.back() > 0 && -s > ans.back()) ans.pop_back();
            if (ans.empty() || ans.back() < 0 || s > 0) ans.push_back(s);
            else if (ans.back() + s == 0) ans.pop_back();
        }

        return ans;
    }
};
// @lc code=end

