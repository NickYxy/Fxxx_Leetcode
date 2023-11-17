/*
 * @lc app=leetcode.cn id=1869 lang=cpp
 *
 * [1869] 哪种连续子字符串更长
 */

// @lc code=start
class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int i = 0,ans_1 = 0,ans_0 = 0;
        while(i < n)
        {
            int start = i;
            i++;
            while(i < n && s[i] == s[start]) i++;
            if(s[start] == '1') ans_1 = max(ans_1, i - start);
            else if(s[start] == '0') ans_0 = max(ans_0, i - start);
        }
        return ans_1 > ans_0;
    }
};
// @lc code=end

