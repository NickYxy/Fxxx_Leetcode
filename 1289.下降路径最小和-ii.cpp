/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        // 可以原地操作
        // vector<vector<int>> dp(n,vector<int>(n));
        // 但是怎么从n的三次方优化到n的2次方呢
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int mi = INT_MAX;
                for (int k = 0; k < n; ++ k) {
                    if (k != j) mi = min(grid[i-1][k], mi);
                }
                grid[i][j] += mi;
            }
        }

        for (int i = 0; i < n; ++ i) {
            ans = min(ans, grid[n - 1][i]);
        }

        return ans;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int first_min_sum = 0;
        int second_min_sum = 0;
        int first_min_index = -1;

        for (int i = 0; i < n; i++) {
            int cur_first_min_sum = INT_MAX;
            int cur_second_min_sum = INT_MAX;
            int cur_first_min_index = -1;

            for (int j = 0; j < n; j++) {
                int cur_sum = (j != first_min_index ? first_min_sum : second_min_sum) + grid[i][j];
                if (cur_sum < cur_first_min_sum) {
                    cur_second_min_sum = cur_first_min_sum;
                    cur_first_min_sum = cur_sum;
                    cur_first_min_index = j;
                } else if (cur_sum < cur_second_min_sum) {
                    cur_second_min_sum = cur_sum;
                }
            }
            first_min_sum = cur_first_min_sum;
            second_min_sum = cur_second_min_sum;
            first_min_index = cur_first_min_index;
        }
        return first_min_sum;
    }
};
// @lc code=end

