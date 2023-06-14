/*
 * @lc app=leetcode.cn id=1375 lang=cpp
 *
 * [1375] 二进制字符串前缀一致的次数
 */

// @lc code=start
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int count = 0, maxCnt = 0;
        for (int i = 0; i < n; ++ i) {
            maxCnt = max(maxCnt, flips[i]);
            if (i + 1 == maxCnt) count ++;
        }

        return count;
    }
};
// @lc code=end

