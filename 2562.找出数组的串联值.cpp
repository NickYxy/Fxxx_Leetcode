/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        long long ans = 0;
        while (i < j && i < n && j >= 0) {
            ans += (nums[i] * count(nums[j]) + nums[j]);
            cout << ans << ' ';
            i ++;
            j --;
        }
        if (i == j) ans += nums[i];
        return ans;
    }

    int count(int num) {
        int cnt = 1;
        while (num) {
            num /= 10;
            cnt *= 10;
        }

        return cnt;
    }
};
// @lc code=end

