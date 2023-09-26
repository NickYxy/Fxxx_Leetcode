/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int direction = 1;
        string res;
        if (numRows < 2) return s;
        for (int i = 0; i < numRows; ++ i) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += 2 * numRows - 2) res += s[j];
            } else {
                for (int j = i, k = 2 * numRows - 2 - i;j < s.size() || k < s.size(); j += 2*numRows - 2, k += 2*numRows - 2) {
                    if (j < s.size()) res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows);
        if (numRows < 2) return s;
        int i = 0, flag = -1;
        for (auto& ch : s) {
            res[i] += ch;
            if (i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }

        string ans = "";
        for (auto& str : res) ans += str;

        return ans;
    }
};
// @lc code=end

