/*
 * @lc app=leetcode.cn id=2574 lang=cpp
 *
 * [2574] 左右元素和的差值
 */

// @lc code=start
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0, right[n - 1] = 0;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                left[i] += nums[j];
            }
        }
        for (int i = n - 2; i >= 0; i --) {
            for (int j = n - 1; j > i; j --) {
                right[i] += nums[j];
            }
        }
        for (int i = 0; i < n; i ++) ans[i] = abs(left[i] - right[i]);
        return ans;
    }
};
// @lc code=end

