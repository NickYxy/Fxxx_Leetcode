/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    vector<int> nums;
    stack<int> st;
    int idx;
    StockSpanner() {
        idx = -1;
    }

    int next(int price) {
        idx ++;
        while (st.size() && price >= nums[st.top()]) st.pop();
        int ans = st.empty() ? idx + 1 : idx - st.top();
        nums.push_back(price);
        st.push(idx);

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

