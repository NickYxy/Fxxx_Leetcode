/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (auto& n : arr) mp[n] ++;

        unordered_set<int> s;
        for (auto& m : mp) s.insert(m.second);

        return s.size() == mp.size();
    }
};
// @lc code=end

