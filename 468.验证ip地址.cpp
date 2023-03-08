/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {
public:
        string checkipv4(string s)
    {
        int k=0,sum=0,t=0;
        bool flag=true;
        for (const auto &ch:s)
        {
            if (!((ch=='.')||((ch>='0')&&(ch<='9')))) return "Neither";   //判断是否存在不合法的字符
            if (ch=='.')
                if (flag) {k=0;sum=0;flag=false;++t;}   //记录是否存在两个连续的‘.’字符
                else return "Neither";
            else
            {
                if (k!=0 && sum==0) return "Neither";  //处理前导零
                sum=sum*10+(ch-'0');
                if (sum>255) return "Neither";   //判断xi是否在0~255
                ++k;flag=true;
            }
        }
        if (t!=3 || !flag) return "Neither";   //判断'.'字符是否只出现3次和最后一位是不是数字结尾
        return "IPv4";
    }

    string checkipv6(string s)
    {
        bool flag=true;
        int t=0,k=0;
        for (const auto &ch:s)
        {
            if (!((ch==':')||((ch>='0')&&(ch<='9'))||((ch>='a')&&(ch<='f'))||((ch>='A')&&(ch<='F'))))
                return "Neither";   //判断是否存在不合法的字符
            if (ch==':')     //记录是否存在两个连续的‘:’字符
                if (!flag) return "Neither";
                else {flag=false;++t;k=0;}
            else {flag=true;++k;}
            if (k>4) return "Neither";  //判断xi是否在0~4位之间
        }
        if (t!=7 || !flag) return "Neither";   //判断':'字符是否只出现7次和最后一位是不是数字结尾
        return "IPv6";
    }

    string validIPAddress(string queryIP)
    {
        for (const auto &ch:queryIP)
        {
            if (ch=='.') return checkipv4(queryIP);
            if (ch==':') return checkipv6(queryIP);
        }
        return "Neither";
    }
};
// @lc code=end

