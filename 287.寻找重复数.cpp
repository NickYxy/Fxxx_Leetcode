/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 巧妙地把数组看成链表，然后当成快慢指针求环的入口问题
        // 首先让慢指针和快指针同时走，如果两者相遇了，注意这时不一定是入口
        // 想一想链表拿到原题，需要此时将快指针扔到head，然后两者同步走
        // 当再次相遇的时候，就是环入口处
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                fast = 0;
                while (nums[slow] != nums[fast]) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return nums[slow];
            }
        }
        return -1;
    }
};
// @lc code=end

