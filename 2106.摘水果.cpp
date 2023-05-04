/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 */

// @lc code=start
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // 这是对官方解答的逐行分析

        // 这两个值的设置为0，是由于数组的初始下标计数是从0开始的，所以设置为0
        int left = 0;
        int right = 0;

        // 这两个值均用于存储所能拿到的水果数，之所以需要两个值，是因为一个用于存储当前窗口能拿到的水果数sum，一个用于存储历史最大值ans，初始都设置为0，即未拿到水果
        int sum = 0;
        int ans = 0;

        // 这里使用auto，实际上是定义了一个求解当前区间相对于startPos进行移动所需要的位置的函数，输入是区间的位置信息[left，right]，返回的是一个int类型的数据
        auto step = [&](int left, int right) -> int {
            //首先判断的是，startPos相对于原始区间的位置，其中分为三种情况，第一种是当前判断区间整体位于startPos的左侧，这样就必须直接走到left，才能够遍历整个区间，第二种，则是整体位于右侧，则需要走到right，才能遍历，第三种情况位于中间如果位于中间，则必须判断是先左走，还是先右走，然后取两者中的较小值，作为最小的步数。
            if (fruits[right][0] <= startPos) {
                return startPos - fruits[left][0];
            } else if (fruits[left][0] >= startPos) {
                return fruits[right][0] - startPos;
            } else {
                return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) + \
                       fruits[right][0] - fruits[left][0];
            }
        };
        // 首先移动右边界，然后判断目前是否超出步数范围，如果未超出，则判断新方案的水果数与过去最大值的关系，取大值，如果超出了，则需要移动左边界，知道步数小于k为止
        while (right < fruits.size()) {
            sum += fruits[right][1];
            // 移动左边界
            while (left <= right && step(left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};

class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int max = 0;
        for (int i = 0, j = 0, sum = 0; i < fruits.length; sum -= fruits[i++][1]) {
            while (j < fruits.length && 2 * Math.max(startPos - fruits[i][0], 0) + Math.max(fruits[j][0] - startPos, 0) <= k) {
                max = Math.max(max, sum += fruits[j++][1]);
            }
        }
        for (int i = 0, j = 0, sum = 0; i < fruits.length; sum -= fruits[i++][1]) {
            while (j < fruits.length && Math.max(startPos - fruits[i][0], 0) + 2 * Math.max(fruits[j][0] - startPos, 0) <= k) {
                max = Math.max(max, sum += fruits[j++][1]);
            }
        }
        return max;
    }
}

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        pos = [fruit[0] for fruit in fruits]
        val = [fruit[1] for fruit in fruits]

        presum = list(accumulate(val, initial = 0))
        ans = 0

        for x in range(k + 1):
            i = bisect_left(pos, startPos - x)
            j = bisect_right(pos, startPos + k - 2 * x)
            res1 = presum[j] - presum[i]

            i = bisect_left(pos, startPos + 2 * x - k)
            j = bisect_right(pos, startPos + x)
            res2 = presum[j] - presum[i]

            ans = max(ans, max(res1, res2))

        return ans
// @lc code=end

