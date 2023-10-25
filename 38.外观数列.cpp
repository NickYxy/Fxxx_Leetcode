/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";

        string temp = "11";
        for (int i = 3; i <= n; ++ i) {
            string ans = "";
            int j = 0, k = 0, count = 0;
            while (j < temp.size() && k < temp.size()) {
                while (temp[j] == temp[k] && j < temp.size() && k < temp.size()) {
                    k ++;
                    count ++;
                }
                ans += to_string(count);
                ans += temp[j];
                j = k;
                count = 0;
            }
            temp = ans;
        }

        return temp;
    }
};
// @lc code=end

