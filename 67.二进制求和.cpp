/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size(), lb = b.size();
        while (la > lb) {
            b = '0' + b;
            lb ++;
        }

        while (lb > la) {
            a = '0' + a;
            la ++;
        }

        int carry = 0;

        for (int i = la - 1; i >= 0; i --) {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = (sum) % 2 + '0';
            carry = sum / 2;
        }

        if (carry > 0) a = '1' + a;
        return a;
    }
    }
};
// @lc code=end

