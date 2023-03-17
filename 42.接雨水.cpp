/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n; i ++) {
            while (stk.size() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (stk.size()) {
                    int h = min(height[i], height[stk.top()]) - height[mid];
                    int w = i - stk.top() - 1;
                    ans += h * w;
                }
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

