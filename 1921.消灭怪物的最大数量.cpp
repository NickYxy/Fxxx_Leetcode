/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

// @lc code=start
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // 谁先到，先消灭谁，如果消灭完上一个，这一个到了，就输了，输出个数
        int n = dist.size();
        vector<double> mp(n);
        for (int i = 0; i < n; i ++) mp[i] = (double)dist[i] / speed[i];
        sort(mp.begin(), mp.end());

        double kill = 0;
        while (kill < n && kill < mp[kill]) kill ++;

        return kill;
    }
};
// @lc code=end

