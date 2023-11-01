/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, int idx) {
        ans.push_back(path);

        for (int i = idx; i < n; ++ i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

