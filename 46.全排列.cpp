/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    void dfs(vector<int>& nums, int start) {
        if (start == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i] == false) {
                path[start] = nums[i];
                used[i] = true;
                dfs(nums, start + 1);
                used[i] = false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        // 不含重复数字
        int n = nums.size();
        used = vector<bool>(n);
        path = vector<int> (n);
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

