/*
 * @lc app=leetcode.cn id=2215 lang=cpp
 *
 * [2215] 找出两数组的不同
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> ans(2);
        unordered_map<int, int> mp1, mp2;

        for (int i = 0; i < m; ++ i) mp1[nums1[i]] ++;
        for (int i = 0; i < n; ++ i) mp2[nums2[i]] ++;

        for (auto& mp : mp1) {
            if (mp2.count(mp.first) == 0) ans[0].emplace_back(mp.first);
        }

        for (auto& mp : mp2) {
            if (mp1.count(mp.first) == 0) ans[1].emplace_back(mp.first);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        unordered_set<int> s1, s2;

        for (auto& n : nums1) s1.insert(n);
        for (auto& n : nums2) s2.insert(n);

        vector<vector<int>> ans;
        for (auto& v : s1) {
            if (!s2.count(v)) v1.emplace_back(v);
        }

        for (auto& v : s2) {
            if (!s1.count(v)) v2.emplace_back(v);
        }


        ans.emplace_back(v1);
        ans.emplace_back(v2);

        return ans;
    }
};
// @lc code=end

