/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for (int i = 0; i <= n; i ++) {
            res.push_back(count(i));
        }

        return res;
    }

    int count(int n) {
        int ans = 0;
        while (n) {
            n &= (n - 1);
            ans ++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        // 偶数的二进制1个数超级简单，因为偶数是相当于被某个更小的数乘2，
        // 乘2怎么来的？在二进制运算中，就是左移一位，也就是在低位多加1个0，那样就说明dp[i] = dp[i / 2]
        // 奇数稍微难想到一点，奇数由不大于该数的偶数+1得到，
        // 偶数+1在二进制位上会发生什么？会在低位多加1个1，
        // 那样就说明dp[i] = dp[i-1] + 1，当然也可以写成dp[i] = dp[i / 2] + 1
        int i = 1;
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++) {
            if (i % 2 == 0)
                ans[i] = ans[i / 2];
            else
                ans[i] = ans[i / 2] + 1;
        }
        return ans;
    }
};

public int[] countBits(int num) {
    // i & (i - 1)可以去掉i最右边的一个1（如果有），
    // 因此 i & (i - 1）是比 i 小的，
    // 而且i & (i - 1)的1的个数已经在前面算过了，
    // 所以i的1的个数就是 i & (i - 1)的1的个数加上1
    int[] res = new int[num + 1];
    for(int i = 1;i<= num;i++){  //注意要从1开始，0不满足
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}
// @lc code=end

