/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // 从前往后数，c一定在k的前面，所以答案一定是c-k的最大值
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int res = 0;
        for (auto& i : croakOfFrogs) {
            if (i == 'c') c ++;
            else if (i == 'r') r ++;
            else if (i == 'o') o ++;
            else if (i == 'a') a ++;
            else if (i == 'k') k ++;
            res = max(c - k, res);
            if (c < r || r < o || o < a || a < k) return -1;
        }
        return c == r && r == o && o == a && a == k ? res : -1;
    }
};
// @lc code=end

