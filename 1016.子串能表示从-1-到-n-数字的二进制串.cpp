/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution {
public:
    bool queryString(string s, int n) {
        //  举个例子，数字4~7这个范围内如果符合条件，那么1~3也就都符合条件了，因为4~7的末两位包含了1~3的所有情况；
        // 同理数字8~15这个范围内如果都符合条件，那么1~7也就都符合条件了。
        // 认真思考一下我们会发现，如果 [N/2+1, N] 这个范围都符合条件，那么所有的N以内的数字就都符合了。所以我们仅需要对这个范围内的数字进行判断即可。
        for (int i = n / 2; i <= n ; ++ i) {
            cout << itoss(i) << endl;
            if (s.find(itoss(i)) == -1) return false;
        }

        return true;
    }

    string itoss(int t) {
        string res = "";
        while (t) {
            if (t % 2 == 0) res += '0';
            else res += '1';
            t /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution:
    def queryString(self, s: str, n: int) -> bool:
    // bin(x) returns 0b1100 etc...
        for x in range(1, n + 1):
            if not bin(x)[2:] in s:
                return False

        return True
// @lc code=end

