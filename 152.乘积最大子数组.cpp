/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /**
        思路： 求最大值，可以看成求被0拆分的各个子数组的最大值。

        当一个数组中没有0存在，则分为两种情况：

        1.负数为偶数个，则整个数组的各个值相乘为最大值；

        2.负数为奇数个，则从左边开始，乘到最后一个负数停止有一个“最大值”，从右边也有一个“最大值”，比较，得出最大值。
        **/
        int n = nums.size();
        int ans = nums[0], a = 1;

        for (auto& num : nums) {
            a = a * num;
            if (ans < a) ans = a;
            if (num == 0) a = 1;
        }

        a = 1;
        for (int i = n - 1; i >= 0; i--) {
            a = a*nums[i];
            if (ans < a) ans = a;
            if (nums[i] == 0) a = 1;
        }

        return ans;
    }
};
// @lc code=end

