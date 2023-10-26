/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> v(2 * n + 1, vector<int>(2 * n + 1));

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (img1[i][j] == 1) {
                    for (int i2 = 0; i2 < n; ++ i2) {
                        for (int j2 = 0; j2 < n; ++ j2) {
                            if (img2[i2][j2] == 1) {
                                v[i - i2 + n][j - j2 + n] += 1;
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (auto& row : v) {
            for (auto& x : row) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};
// @lc code=end

