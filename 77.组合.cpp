/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ans;
    }

    void backtrack(int n, int k, int cur) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i = cur; i <= n - (k - path.size()) + 1; ++ i) {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

