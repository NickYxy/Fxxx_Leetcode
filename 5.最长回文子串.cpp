/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    //1.判断是否回文字符串；2.判断过程中记录长度；3.注意两种形式
    int l, r, maxlen;
    void isPalindrome(string s, int i, int j, int n) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            if ((j - i + 1) > maxlen) {
                maxlen = j - i + 1;
                l = i, r = j;
            }
            i --;
            j ++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        for (int i = 0; i < n; i ++) {
            isPalindrome(s, i, i, n);
            isPalindrome(s, i, i + 1, n);
        }
        string ans;
        ans = s.substr(l, maxlen);
        return ans;
    }
};
// @lc code=end

