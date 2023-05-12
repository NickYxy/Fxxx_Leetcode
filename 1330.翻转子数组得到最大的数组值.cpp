/*
 * @lc app=leetcode.cn id=1330 lang=cpp
 *
 * [1330] 翻转子数组得到最大的数组值
 */

// @lc code=start
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        // 怎能能保证两个相邻数之差的绝对值之和最大
        // 翻转子数组只能影响端点的两个数以及和他们相邻的两个数
        // 首先先化简题目，根据求和的规则，可以看出翻转区间实际上只是对于两端点的值会改变，问题变成了选择两个端点交换，求变化量最大值
        // 对于端点附近的4个值（如果端点不在首尾），构成两个数对{{a,b},{c,d}}，我们把含有四个数中最大值的叫做较大对，含有最小值的为较小对。
        // 可以发现如果要增加，只有可能每次的变化量为 2*(较大对的较小值 减 较小对的较大值)，因此，我们维护遍历过的较大对的较小值（lowmax），以及较小对的较大值（highmin），
        // 并且与遍历到的数对比较（分别假设当前述对作为较大对或者较小对即可），求出变化量，并记录变化量的最大值作为答案
        // 而对于端点在首位的情况，直接单独计算即可，也记录这种情况的最大变化量（代码中的ot）最后返回sum（不操作情况下的和）与以上两种变化量较大者的和即可
        int sum = 0, lowmax = INT_MIN, highmin = INT_MAX, ot = 0;
        for (int i = 1; i < nums.size(); ++ i) {
            int x = nums[i - 1], y = nums[i], d = abs(x - y);
            lowmax = max(lowmax, min(x, y));
            highmin = min(highmin, max(x, y));
            sum += d;
            ot = max({ot, abs(nums[0] - y) - d, abs(x - nums.back()) - d});
        }

        return max((lowmax - highmin) * 2, ot) + sum;
    }
};
// @lc code=end

