/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        // 快速幂算法，每次i减半，但是x自乘相当于加倍，如果中间i为奇数，那么最后要乘以一个x；
        // 否则最后倍数就是1
        double res = 1.0;
        for(int i = n; i != 0; i /= 2){
            if(i % 2 != 0){
                res *= x;
            }
            x *= x;
        }
        return  n < 0 ? 1 / res : res;
    }
};
// @lc code=end

