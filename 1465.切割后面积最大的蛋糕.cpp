/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int hmax = max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); ++ i) {
            hmax = max(hmax, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        int wmax = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < verticalCuts.size(); ++ i) {
            wmax = max(wmax, verticalCuts[i] - verticalCuts[i - 1]);
        }

        return (long long)hmax * wmax % mod;
    }
};
// @lc code=end

