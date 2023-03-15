/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        // 任何大于1的数都可由2和3相加组成（根据奇偶证明）
        // 因为2*2=1*4，2*3>1*5, 所以将数字拆成2和3，能得到的积最大
        // 因为2*2*2<3*3, 所以3越多积越大 时间复杂度O(n/3)，用幂函数可以达到O(log(n/3)),
        // 经过拉格朗日条件极值计算得出每段相等时最大，当m = n/e时，即每段都为自然对数e时乘积最大，
        // 但此题只能是整数，所以就看2，3的个数，明显3越多，乘积越大
        if (n <= 3) return n - 1;
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        return ans * n;
    }
};
// @lc code=end

