/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */

// @lc code=start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (total < cost1 && total < cost2) return 1;
        long long ans = 0;
        int m = total / cost1 + 1;
        while (m --) {
            int temp = total;
            temp -= m * cost1;
            if (temp == 0) ans ++;
            else ans += (temp / cost2 + 1);
        }

        return ans;
    }
};
// @lc code=end

