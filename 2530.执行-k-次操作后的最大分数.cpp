/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        int n = nums.size();
        for (auto& num : nums) pq.push(num);

        while (k --) {
            int temp = pq.top();
            ans += temp;
            pq.pop();
            temp = temp % 3 == 0 ? (temp / 3) : (temp / 3) + 1;
            pq.push(temp);
        }

        return ans;
    }
};
// @lc code=end

