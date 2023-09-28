/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // 如何快速找到某个数一共在多少个区间内
        map<int, int> mp;
        for (auto &it : flowers) mp[it[0]] ++, mp[it[1] + 1] --;
        for (auto &x : people) mp[x];

        int total = 0;
        for (auto &[x, y] : mp) {
            total += y;
            y = total;
        }

        for (auto &x : people) {
            x = mp[x];
        }

        return people;
    }
};
// @lc code=end

