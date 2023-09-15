/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        if (s.size() == 0) return true;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            if (i == s.size()) return true;
            j ++;
        }

        return false;
    }
};
// @lc code=end

