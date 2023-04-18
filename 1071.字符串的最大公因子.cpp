/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans;
        if (str1 + str2 != str2 + str1) return "";
        int m = str1.size(), n = str2.size();
        int k = gcd(m, n);
        return str1.substr(0, k);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        n = gcd(len(str1), len(str2))
        return str1[:n]
// @lc code=end

