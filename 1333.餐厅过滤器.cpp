/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;
        sort(restaurants.begin(), restaurants.end(), [&](vector<int> &x, vector<int> &y) {return x[1] != y[1] ? x[1] > y[1] : x[0] > y[0];});
        if (veganFriendly == 0) {
            for (auto res : restaurants) {
                if (res[3] <= maxPrice && res[4] <= maxDistance) ans.push_back(res[0]);
            }
        } else {
            for (auto res : restaurants) {
                if (res[3] <= maxPrice && res[4] <= maxDistance && res[2] == 1) ans.push_back(res[0]);
            }
        }

        return ans;
    }
};
// @lc code=end

