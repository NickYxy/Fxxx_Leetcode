/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // 可以得到判断正整数 n 是否可以表示成 k 个连续正整数之和的方法：

        // 如果 k 是奇数，则当 n 可以被 k 整除时，正整数 n 可以表示成 k 个连续正整数之和；

        // 如果 k 是偶数，则当 n 不可以被 k 整除且 2n 可以被 k 整除时，正整数 n 可以表示成 k 个连续正整数之和。

        int ans = 0;
        int bound = 2 * n;
        for (int i = 1; i * (i + 1) <= bound; ++ i) {
            if (isKConsecutive(n, i)) ans ++;
        }

        return ans;
    }

    bool isKConsecutive(int n, int k) {
        if (k % 2 == 1) {
            return n % k == 0;
        } else {
            return n % k != 0 && 2 * n % k == 0;
        }
    }
};


class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // (a + b) * (a - b + 1) / 2
        // 双指针超时
        int count = 1;
        int mid = n / 2 + 1;
        for (int i = 1; i <= mid; ++ i) {
            for (int j = i + 1; j <= mid; ++ j) {
                int temp = (j + i) * (j - i + 1);
                if (temp == 2 * n) {
                    count ++;
                    break;
                } else if (temp > 2 * n) break;
            }
        }

        return count;
    }
};
// @lc code=end

