/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1000 * 1000);// dp[i(第几本书)] = 所占的最小高度
        dp[0] = 0;

        for (int i = 1; i <= n; ++ i) { // 既有第几层的含义又有第几本书的含义
            int w = 0, h = 0;
            for (int j = i; j >= 1; -- j) {
                w += books[j - 1][0];// 想把前面几本书都放在第i层
                if (w > shelfWidth) break;// 放不下了就break
                h = max(h, books[j - 1][1]);// 前几本书的最大高度就是本层的高度
                dp[i] = min(dp[i], dp[j - 1] + h);
            }
        }

        return dp[n];
    }
};
// @lc code=end

