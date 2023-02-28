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

// 归并排序会更好一些，速度也更快，空间占用也小
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i ++ ; j ++ ;
            } else if (nums1[i][0] < nums2[j][0]) {
                ans.push_back(nums1[i]);
                i ++ ;
            } else {
                ans.push_back(nums2[j]);
                j ++ ;
            }
        }
        while (i < n1) {
            ans.push_back(nums1[i]);
            i ++ ;
        }
        while (j < n2) {
            ans.push_back(nums2[j]);
            j ++ ;
        }
        return ans;
    }
};
// @lc code=end

