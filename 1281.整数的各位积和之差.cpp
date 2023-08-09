/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int multi = 1, sum = 0;
        while (n) {
            int t = n % 10;
            n /= 10;
            multi *= t;
            sum += t;
        }

        return multi - sum;
    }
};
// @lc code=end

