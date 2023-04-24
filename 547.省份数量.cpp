/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++ i) {
            if (visited[i] == false) {
                dfs(isConnected, visited, i);
                ans ++;
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        for (int j = 0; j < isConnected.size(); ++ j) {
            if (isConnected[i][j] == 1 && visited[j] == false) {
                visited[j] = true;
                dfs(isConnected, visited, j);
            }
        }
    }
};
// @lc code=end

