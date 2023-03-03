/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        void dfs(vector<int>& nums, int start) {
            ans.push_back(path);
            if (start >= nums.size()) return;
            for (int i = start; i < nums.size(); i ++) {
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            dfs(nums, 0);
            return ans;
        }
    }
};
// @lc code=end

