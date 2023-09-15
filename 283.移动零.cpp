/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), s = 0;
        for (int i = 0; i < n; ++ i) {
            if (nums[i] != 0) {
                nums[s++] = nums[i];
            }
        }

        for (int i = s; i < n; ++ i) {
            nums[i] = 0;
        }

        return;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && nums[i] != 0) i ++;
            j = i;
            while (j < n && nums[j] == 0) j ++;
            if (i < n && j < n) swap(nums[i], nums[j]);
            i ++;
            j ++;
        }

        return;
    }
};
// @lc code=end

