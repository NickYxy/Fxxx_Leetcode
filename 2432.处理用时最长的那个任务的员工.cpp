/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 *
 * [2432] 处理用时最长的那个任务的员工
 */

// @lc code=start
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int idx = 0, cnt = 0, end = 0;
        for (int i = 0; i < logs.size(); ++ i) {
            if (i) end = max(end, logs[i - 1][1]);
            if (cnt < (logs[i][1] - end)) {
                idx = logs[i][0];
                cnt = logs[i][1] - end;
            } else if (cnt == (logs[i][1] - end)) {
                idx = min(idx, logs[i][0]);
            }
        }

        return idx;
    }
};
// @lc code=end

