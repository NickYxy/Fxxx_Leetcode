/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 *
 * [1015] 可被 K 整除的最小整数
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        if (k == 1) return 1;
        int cnt = 0;
        // 从除法余数的角度来说，在做竖式的时候，余数种类最多k种，因此枚举到k位没找到的话，说明找不到了
        for (int i = 1; i <= k; ++ i) {
            cnt = (cnt * 10 + 1) % k;
            if (cnt == 0) return i;
        }

        return -1;
    }
};
// @lc code=end

