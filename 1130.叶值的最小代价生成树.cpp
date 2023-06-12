/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (n == 2) return arr[0] * arr[1];

        stack<int> stk;
        stk.push(INT_MAX);
        int ans = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            while (stk.top() < arr[i]) {
                int t = stk.top();
                stk.pop();
                ans += t * min(arr[i], stk.top());
            }
            stk.push(arr[i]);
        }

        while (stk.size() > 2) {
            int t = stk.top();
            stk.pop();
            ans += t * stk.top();
        }

        return ans;
    }
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 4)), mval(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            mval[j][j] = arr[j];
            dp[j][j] = 0;
            for (int i = j - 1; i >= 0; i--) {
                mval[i][j] = max(arr[i], mval[i + 1][j]);
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

