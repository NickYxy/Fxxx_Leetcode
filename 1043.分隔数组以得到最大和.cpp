/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // dp[i]表示最后一段以arr[i]结尾所能达到的最大值。
        // 依次向前枚举开头（最多k个），复杂度O(NK)
        int n = arr.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            int mx = 0;
            for (int j = i - 1; j >= -1 && i - j <= k; --j) {
                mx = max(mx, arr[j + 1]);
                dp[i] = max(dp[i], (j >= 0 ? dp[j] : 0) + (i - j) * mx);
            }
        }
        return dp.back();
    }
};
// @lc code=end

