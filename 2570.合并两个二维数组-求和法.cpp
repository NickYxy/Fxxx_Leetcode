/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 *
 * [2570] 合并两个二维数组 - 求和法
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> mp;
        for (auto& item : nums1) {
            mp[item[0]] = item[1];
        }
        for (auto& item: nums2) {
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

