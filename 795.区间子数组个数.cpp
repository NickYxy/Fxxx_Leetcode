/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, temp = 0, j = -1;
        for (int i = 0; i < nums.size(); i ++) {
            // 核心思路就是：“连续子数组”，所以子数组里面必须有一个值大于等于left，但是坚决不能大于right，其他的可以小于left
            // 这样在检查数组的时候，前方的数字满足条件，那么后面的数字如果满足条件temp++(i++，j不变)
            // 如果后面的数字小于left，那么temp不变；如果大于right，temp清零
            if (nums[i] > right) j = i;
            if (nums[i] >= left) temp = i - j;
            ans += temp; // 最终结果都是+temp，但是temp的值视情况而变
        }
        return ans;
    }
};
// @lc code=end

