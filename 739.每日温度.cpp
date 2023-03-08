/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈做法，保持单调栈递减，遇到比栈顶大的元素，则结算
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i ++ ) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

