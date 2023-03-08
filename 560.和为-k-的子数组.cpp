/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /**
        遍历数组nums，计算从第0个元素到当前元素的和，用哈希表保存出现过的累积和sum的次数。
        如果sum - k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum。
        时间复杂度为$O(n)$，空间复杂度为$O(n)$。
        **/
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto& num : nums) {
            sum += num;
            ans += mp[sum - k];
            mp[sum] ++;
        }
        return ans;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 如果不理解上面解法的初始化mp[0] = 1,可以这样写
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            sum += num;
            if (sum == k) ans ++; // 重点就在这里,防止错过从i = 0 加到sum == k这种情况
            ans += mp[sum - k];
            mp[sum] ++;
        }
        return ans;
    }
};
// @lc code=end

