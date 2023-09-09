/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, int x) {
        if (x == graph.size() - 1) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < graph[x].size(); ++ i) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }
    }
};
// @lc code=end

