/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < 30; ++ i) {
            for (int j = 0; j < 30; ++ j) {
                if (pow(x, i) > bound || pow(y, j) > bound) break;
                int tmp = pow(x, i) + pow(y, j);
                if (tmp <= bound && mp[tmp] == 0) ans.emplace_back(tmp);
                mp[tmp] ++;
            }
        }

        return ans;
    }
};
// @lc code=end

