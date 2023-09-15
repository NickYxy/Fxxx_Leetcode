/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(n)时间复杂度 O(1)空间复杂度  no divide
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; ++ i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; -- i) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(n)时间复杂度 O(1)空间复杂度  no divide
        int n = nums.size();
        vector<int> ans(n);
        //int left = 1, right = 1;
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++ i) {
            left[i] = nums[i - 1] * left[i - 1];
        }

        for (int i = n - 2; i >= 0; -- i) {
            right[i] = nums[i + 1] * right[i + 1];
        }

        for (int j = 0; j < n; ++ j) {
            ans[j] = left[j] * right[j];
        }

        return ans;
    }
};
// @lc code=end

