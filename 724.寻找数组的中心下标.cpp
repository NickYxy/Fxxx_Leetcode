/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum;
        sum = nums;
        for (int i = 1; i < sum.size(); ++ i) {
            sum[i] += sum[i - 1];
        }

        for (int i = 0; i < nums.size(); ++ i) {
            int left = sum[i] - nums[i];
            int right = sum.back() - sum[i];
            if (left == right) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
        }
        int sumleft = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (sumleft * 2 + nums[i] == sum) return i;
            sumleft += nums[i];
        }

        return -1;
    }
};
// @lc code=end

