/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] 工作计划的最低难度
 */

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // 将任务分成d段，使得每一段的最大值加起来最小
        // f[i][j] 表示前 i + 1 天完成 j 项工作的最小难度
        // f[i][j] = f[i - 1][k] + max(job[k + 1]...job[j])
        int n = jobDifficulty.size();
        if (d > n) return -1;
        int f[d][n];
        memset(f, 0x3f, sizeof(f));

        int maxval = 0;
        for (int j = 0; j < n; ++ j) {
            maxval = max(maxval, jobDifficulty[j]);
            f[0][j] = maxval;
        }

        for (int i = 1; i < d; ++ i) {
            for (int j = i; j < n; ++ j) {
                maxval = 0;
                for (int k = j - 1; k >= 0; k -- ) {
                    maxval = max(maxval, jobDifficulty[k + 1]);
                    f[i][j] = min(f[i][j], f[i - 1][k] + maxval);
                }
            }
        }

        return f[d - 1][n - 1];
    }
};
// @lc code=end

