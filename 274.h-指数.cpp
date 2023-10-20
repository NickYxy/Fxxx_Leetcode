/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; ++ i) {
            int temp = min(n - i, citations[i]);
            ans = max(ans, temp);
        }

        return ans;
    }
};
// @lc code=end

