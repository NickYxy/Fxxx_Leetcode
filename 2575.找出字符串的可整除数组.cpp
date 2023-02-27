/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 *
 * [2575] 找出字符串的可整除数组
 */

// @lc code=start
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        // 大数溢出问题，一是要long long声明，二是要提前%
        int n = word.size();
        vector<int> ans(n);
        long long temp = 0;
        for (int i = 0; i < n; i ++) {
            temp = (temp * 10 + (word[i] - '0')) % m;
            if (temp == 0) ans[i] = 1;
            else ans[i] = 0;
        }

        return ans;
    }
};
// @lc code=end

