/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), pre = 0, ans = 0;
        for (int i = 0; i < n; ++ i) {
            if (seats[i] == 1) {
                if (pre == 0 && seats[pre] != 1) ans = max(ans, i - pre);
                ans = max(ans, (i - pre) / 2);
                pre = i;
            }
        }

        ans = max(ans, n - pre - 1);

        return ans;
    }
};
// @lc code=end

