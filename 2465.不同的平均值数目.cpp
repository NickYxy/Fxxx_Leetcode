/*
 * @lc app=leetcode.cn id=2465 lang=cpp
 *
 * [2465] 不同的平均值数目
 */

// @lc code=start
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> mp;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            double t = (nums[i] + nums[j]) / 2.0;
            mp.insert(t);
            i ++;
            j --;
        }

        return mp.size();
    }
};
// @lc code=end

