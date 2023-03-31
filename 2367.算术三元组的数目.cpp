/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */

// @lc code=start
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++) {
            mp[nums[i]] ++;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size() - 2; i ++) {
            if (mp[nums[i] + diff] && mp[nums[i] + diff + diff]) cnt ++;

        }
        return cnt;
    }
};
// @lc code=end

