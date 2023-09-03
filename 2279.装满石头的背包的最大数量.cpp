/*
 * @lc app=leetcode.cn id=2279 lang=cpp
 *
 * [2279] 装满石头的背包的最大数量
 */

// @lc code=start
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans = 0, n = rocks.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i ++) temp[i] = capacity[i] - rocks[i];
        sort(temp.begin(), temp.end());

        for (auto &t : temp) {
            if (t == 0) ans ++;
            else if (t > 0 && additionalRocks >= t) {
                additionalRocks -= t;
                ans ++;
            } else break;
        }

        return ans;
    }
};
// @lc code=end

