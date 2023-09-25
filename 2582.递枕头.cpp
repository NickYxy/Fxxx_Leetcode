/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        int dirc =  time / (n - 1);
        int cnt = time % (n - 1);
        if (dirc % 2 == 0) return cnt + 1;
        else return n - cnt;
    }
};
// @lc code=end

