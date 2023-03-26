/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        string tool = "aeiouAEIOU";
        while (i < j) {
            while (i < j && tool.find(s[i]) == -1) i ++;
            while (i < j && tool.find(s[j]) == -1) j --;
            if (i < j) swap(s[i], s[j]);
            i ++;
            j --;
        }
        return s;
    }
};
// @lc code=end

