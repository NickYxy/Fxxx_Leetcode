/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int minDiff = INT_MAX, n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; ++ i) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) continue;

            int sum = x + nums[i + 1] + nums[i + 2];

            if (sum > target) {
                if (sum - target < minDiff) ans = sum;
                break;
            }

            sum = x + nums[n - 2] + nums[n - 1];
            if (sum < target) {
                if ((target - sum) < minDiff) {
                    minDiff = target - sum;
                    ans = sum;
                }
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k) {
                sum = x + nums[j] + nums[k];
                if (sum == target) return target;
                if (sum > target) {
                    if ((sum - target) < minDiff) {
                        minDiff = sum - target;
                        ans = sum;
                    }
                    k --;
                }
                else {
                    if (target - sum < minDiff) {
                        minDiff = target - sum;
                        ans = sum;
                    }
                    j ++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

