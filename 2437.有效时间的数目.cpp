/*
 * @lc app=leetcode.cn id=2437 lang=cpp
 *
 * [2437] 有效时间的数目
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int countTime(string time) {
        dfs(time, 0);
        return ans;
    }

    void dfs(string& time, int index) {
        if (index == time.size()) {
            if ((time[0] - '0') * 10 + time[1] - '0' <= 23 && (time[3] - '0') * 10 + time[4] - '0' <= 59) ans ++;
            return;
        }

        if (time[index] == '?') {
            for (int i = 0; i < 10; ++ i) {
                time[index] = i + '0';
                dfs(time, index + 1);
                time[index] = '?';
            }
        } else {
            dfs(time, index + 1);
        }
    }
};
// @lc code=end

