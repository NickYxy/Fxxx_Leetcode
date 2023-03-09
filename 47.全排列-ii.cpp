/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (i && !used[i - 1] && (nums[i] == nums[i - 1])) continue;
            if (used[i] == false) {
                path[index] = (nums[i]);
                used[i] = true;
                dfs(nums, index + 1);
                used[i] = false;
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        path = vector<int> (n);
        used = vector<bool> (n, false);
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

