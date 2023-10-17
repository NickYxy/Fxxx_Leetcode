/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int x[26] = {0}, y[26] = {0};
        for (int i = 0; s[i] != '\0'; i ++) x[s[i] - 'a'] ++;
        for (int i = 0; t[i] != '\0'; i ++) y[t[i] - 'a'] ++;
        for (int i = 0; i < 26;i ++ ) {
            if (x[i] != y[i]) return false;
        }

        return true;
    }
};
// @lc code=end

