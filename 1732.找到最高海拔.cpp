/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = -100008, start = 0;
        for (auto& x : gain) {
            start += x;
            ans = max(ans, start);
        }

        return ans > 0 ? ans : 0;
    }
};
// @lc code=end

