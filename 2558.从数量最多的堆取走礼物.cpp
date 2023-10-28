/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while (k --) {
            int t = pq.top();
            if (t == 1) break;
            pq.pop();
            pq.push(sqrt(t));
        }

        long long ans = 0;
        while (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

