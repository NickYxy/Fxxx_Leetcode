/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 八个方向移动，如何定义八个方向
        // 如何O1判断是否是皇后，set或者数组都可以
        int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0}, dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
        vector<vector<int>> ans;

        int isqueen[8][8];
        memset(isqueen, 0, sizeof(isqueen));
        for (auto& q : queens) isqueen[q[0]][q[1]] = 1;

        for (int i = 0; i < 8; ++ i) {
            for (int x = king[0] + dx[i], y = king[1] + dy[i];; x += dx[i], y += dy[i]) {
                if (x >= 8 || x < 0 || y >= 8 || y < 0) break;
                if (isqueen[x][y] == 1) {
                    ans.push_back({x, y});
                    break;
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<int> queen_pos;
        for (const auto& queen: queens) {
            int x = queen[0], y = queen[1];
            queen_pos.insert(x * 8 + y);
        }

        vector<vector<int>> ans;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                int kx = king[0] + dx, ky = king[1] + dy;
                while (kx >= 0 && kx < 8 && ky >= 0 && ky < 8) {
                    int pos = kx * 8 + ky;
                    if (queen_pos.count(pos)) {
                        ans.push_back({kx, ky});
                        break;
                    }
                    kx += dx;
                    ky += dy;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

