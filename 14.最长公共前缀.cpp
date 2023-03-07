/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()) return ans;
        for (int i = 0;; i ++) {
            if (i >= strs[0].size()) return ans;
            char c = strs[0][i];
            for (auto& str : strs) {
                if (str.size() <= i || str[i] != c) return ans;
            }
            ans += c;
        }
        return ans;
    }
};
// @lc code=end

