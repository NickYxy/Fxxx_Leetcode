/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
    }

    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int i = l - 1, j = r + 1;
        int mid = nums[(l + r) >> 1];
        while (i < j && i < r && j >= l) {
            do i ++; while (nums[i] < mid);
            do j --; while (nums[j] > mid);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /**
        i指针之前的都是0，k指针后面的都是2。j是工作指针，nums[j]==0时和前面的i指针的内容交换，
        此时i指针所指的一定是1，因为如果是0，j指针从左往右扫的时候会把它放到i指针之前，
        如果是2，j指针从左往右扫的时候会把它被放到k之后。
        而nums[j]==2时 j指针和k指针进行交换后，此时j所指的数0，1，2都有可能，
        因为k在j右边，没有扫过，所以交换后j还不能自增，得继续判断当前数字。
        **/
        int n = nums.size();
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i ++;
                j ++;
            } else if (nums[j] == 2) {
                swap(nums[j], nums[k]);
                k --;
            } else {
                j ++;
            }
        }
    }
};
// @lc code=end

