/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 防御式编程思想：在 flowerbed 数组两端各增加一个 0，
        // 这样处理的好处在于不用考虑边界条件，任意位置处只要连续出现三个 0 就可以栽上一棵花。
        int m = flowerbed.size();
        for (int i = 0; i < m; i ++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == m - 1 || flowerbed[i + 1] == 0)) {
                n --;
                flowerbed[i] = 1;
            }
        }

        return n <= 0; // 注意n用完后依然可以继续用，笑
    }
};
// @lc code=end

