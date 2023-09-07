/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */

// @lc code=start
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // 能力值 * 平方，如何使得最长时间尽量小
        // 能力值大的，尽量少修；能力值小的，尽量多修；

        long long l = 1, r = 1e14, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (F(ranks, cars, m)) r = m - 1;
            else l = m + 1;
        }
        return l;

    }

    bool F(vector<int>& ranks, int cars, long long m) {
        long long s = 0;
        for (auto &x : ranks) {
            s += sqrt(m/x);
        }

        return s >= cars;
    }
};
// @lc code=end

