/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

// @lc code=start
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            if (num % 2 == 0) mp[num] ++;
        }

        if (mp.empty()) return -1;
        int ma = INT_MIN, cnt = 0;
        for (auto& [k, v] : mp) {
            if ((k < ma && v == cnt) || v > cnt) {
                ma = k;
                cnt = v;
            }
        }
        return ma;
    }
};
// @lc code=end

