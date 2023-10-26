/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1, j = n - 1;
        while (j >= 0 && s[j] == ' ') j --;
        i = j;
        while (i >= 0 && s[i] != ' ') i --;

        return j - i;
    }
};
// @lc code=end

