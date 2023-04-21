/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    int seen[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);

        for (int i = 0; i < rooms.size(); ++ i) {
            if (seen[i] == 0) return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int key) {
        if (seen[key]) return;
        seen[key] = 1;

        vector<int> keys = rooms[key];
        for (auto key : keys) dfs(rooms, key);
    }
};
// @lc code=end

