/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        /**
         * @brief 本题的思路有种数学归纳法的感觉。需要考虑的就是这样一个问题：

                当我们已经可以表示[0,n]时，再给一个整数x，可以表示的整数范围如何变化？
                显然，新增的可达数就是把原来的n+1个数都加上x，得到[x,n+x]，
                新的可以表示的数的范围就是这两部分的并集。
                在本题中，要求可达域连续，也就是要求x<=n+1，这样可达域就被扩充为[0,n+x]。
                初始可达域为{0}，由于x<=n+1的条件限制
                我们肯定是从小到大地添加数。我们维护当前可以表示的最大值，也就是上面的n，
                如果当前最小数满足条件，就添加之，并更新最大值；否则就没有有可以添加的数了，返回答案。
         *
         */
        sort(coins.begin(), coins.end());
        int canGet = 0;
        for (int &coin : coins) {
            if (coin <= canGet + 1) //如果当前最小数满足条件，添加并更新
                canGet += coin;
            else break;
        }
        return canGet + 1;
    }
};
// @lc code=end

