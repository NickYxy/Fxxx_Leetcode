/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i ++;
            j --;
        }
    }
};
// @lc code=end

