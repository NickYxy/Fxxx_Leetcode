/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /**
        为什么二分查找大的那一半一定会有峰值呢？（
        即nums[mid]<nums[mid+1]时，mid+1~N一定存在峰值）
        首先已知 nums[mid+1]>nums[mid]，那么mid+2只有两种可能，一个是大于mid+1，一个是小于mid+1，
        小于mid+1的情况，那么mid+1就是峰值，大于mid+1的情况，继续向右推，
        如果一直到数组的末尾都是大于的，那么可以肯定最后一个元素是峰值，因为nums[nums.length]=负无穷
        **/
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (r + l) >> 1;
            if (nums[mid] < nums[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};
// @lc code=end

