/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (i < s.size() && s[i] == ' ') continue;
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ') s[t ++ ] = s[j ++ ];
            reverse(s.begin() + k, s.begin() + t);
            s[t ++ ] = ' ';
            i = j, k = t;
        }
        if (k) k--;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        // 移除头尾多余的空格
        int headspace = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                headspace++;
            }else{
                break;
            }
        }
        int tailspace = 0;
        for(int i = s.size() -1; i >=0; i--)
        {
            if(s[i] == ' ')
            {
                tailspace++;
            }else{
                break;
            }
        }
        s = s.substr(headspace, s.size() - headspace - tailspace);

        int i = s.size()-1;
        int j = s.size() - 1;
        string res = "";
        // 使用双指针把单词拆分出来，并填充到res中

        while(i >= 0)
        {
            while(i >= 0 && s[i] != ' ') i--;
            res.append(s.substr(i+1, j-i));
            res += " ";
            while(i >=0 && s[i] == ' ') i--;
            j = i;
        }
        // 去掉尾部的一个多余空格
        res = res.substr(0, res.size() - 1);

        return res;
    }

};
// @lc code=end

