/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i ++) {
            for (int j = 0; j < t.size(); j ++) {
                int diff = 0, k = 0;
                while ((i + k < s.size()) && (j + k < t.size()) && diff < 2) {
                    diff += (s[i + k] != t[j + k]);
                    ans += (diff == 1);
                    k ++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

