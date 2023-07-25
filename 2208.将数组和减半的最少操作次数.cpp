/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double half;
        for (auto& num : nums) half += num;
        half /= 2;
        priority_queue<double, vector<double>, less<double>> pq;
        for (auto& num : nums) {
            pq.push(double(num));
        }

        int ans = 0;
        double total = 0.0;
        while (total < half) {
            double temp = pq.top();
            pq.pop();
            temp /= 2;
            total += temp;
            pq.push(temp);
            ans ++;
        }

        return ans;
    }
};
// @lc code=end

