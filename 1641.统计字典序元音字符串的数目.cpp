/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        //将n个球放入可为空的m个篮子里 == 将n + m个球放入不能为空的m个篮子里
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return accumulate(dp, dp + 5, 0);
    }
}

// @lc code=end

