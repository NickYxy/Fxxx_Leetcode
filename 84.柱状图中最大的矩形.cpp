/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 对栈中柱体来说，栈中的下一个柱体就是其「左边第一个小于自身的柱体」；
        // 若当前柱体 i 的高度小于栈顶柱体的高度，说明 i 是栈顶柱体的「右边第一个小于栈顶柱体的柱体」。
        // 因此以栈顶柱体为高的矩形的左右宽度边界就确定了，可以计算面积
        heights.push_back(0); // 首尾加上两个虚拟柱子，为了求左边第一个小于和右边第一个小于
        heights.insert(heights.begin(), 0);
        int n = heights.size();
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            while (stk.size() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                ans = max(ans, (i - stk.top() - 1) * h);
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

