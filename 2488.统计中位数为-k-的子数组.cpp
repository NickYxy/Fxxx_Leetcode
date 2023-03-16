/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int k_index = -1;
        // find k index
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == k) {
                k_index = i;
                break;
            }
        }

        if (k_index == -1) return 0; // If k doesn't exist, return 0
        int presum = 0; // presum
        unordered_map<int, int> mp;
        mp[0] = 1; // 0出现的次数为1
        int ans1 = 0, ans2 = 0; // 记录答案
        for (int i = 0; i < nums.size(); i ++) {
            // 大于k转成1，小于k转成-1，等于k转成0
            int cur = nums[i] == k ? 0 : (nums[i] > k ? 1 : -1);
            presum += cur;
            if (i < k_index) {// 此时还没出现k，只需统计前缀和就行
                mp[presum] ++;
            } else {
                ans1 += mp[presum];// 第一种情况，奇数个 ，大于k和小于k数量相等
                ans2 += mp[presum - 1];// 第二种情况，偶数个，大于k比小于k数量多1
            }

        }

        return ans1 + ans2;
    }
};
// @lc code=end

