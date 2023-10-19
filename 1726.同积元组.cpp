/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            for (int j = 0; j < i; ++ j) {
                int temp = nums[i] * nums[j];
                ans += mp[temp];
                mp[temp] ++;
            }
        }

        return ans * 8;
    }
};
// @lc code=end

