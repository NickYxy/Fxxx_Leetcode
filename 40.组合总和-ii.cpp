/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int sum, int start) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i ++) {
            if (i> start && candidates[i] == candidates[i - 1]) continue; // 保证本层不重复 但不同层可以重复
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }

    }
};
// @lc code=end

