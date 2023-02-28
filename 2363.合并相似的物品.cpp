/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        //map自带排序，也可以用map
        unordered_map<int, int> mp;
        for (auto& item : items1) {
            mp[item[0]] = item[1];
        }
        for (auto& item: items2) {
            if (mp.count(item[0])) mp[item[0]] += item[1];
            else mp[item[0]] = item[1];
        }
        vector<vector<int>> ans;
        for (auto& item : mp) ans.push_back({item.first, item.second});
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

