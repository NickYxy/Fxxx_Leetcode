/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
      vector<vector<int>> ans;
      int i = 0, j = 1;
      while (i < s.size() && j < s.size()) {
        while (i < j && s[j] == s[i]) j ++;
        if (j - i >= 3) ans.push_back({i, j - 1});
        i = j;
        j ++;
      }

      return ans;
    }
};
// @lc code=end

