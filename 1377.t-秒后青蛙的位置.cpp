/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */

// @lc code=start
class Solution {
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0}; // 减少额外判断的小技巧
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }
        double ans = 0;

        function<bool(int, int, int, long long)> dfs = [&](int x, int fa, int left_t, long long prod) -> bool {
            // t 秒后必须在 target（恰好到达，或者 target 是叶子停在原地）
            if (x == target && (left_t == 0 || g[x].size() == 1)) {
                ans = 1.0 / prod;
                return true;
            }
            if (x == target || left_t == 0) return false;
            for (int y: g[x])  // 遍历 x 的儿子 y
                if (y != fa && dfs(y, x, left_t - 1, prod * (g[x].size() - 1)))
                    return true; // 找到 target 就不再递归了
            return false; // 未找到 target
        };

        dfs(1, 0, t, 1);
        return ans;
    }
};
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // use a variation of dfs with parameters current_vertex and current_time
        // update the possibility considering to jump to one of the children vertices
        double ans = 0;
        vector<vector<int>> e(n + 1);
        for (auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }
        vector<int> visited(n + 1);

        function<void(int, double, int)> dfs = [&](int now, double probility, int time) {
            if (now == target) {
                if (time == 0) ans = probility;
                else if (time > 0) {
                    if (e[now].size() > 1 || (now == 1 && e[now].size() >= 1)) ans = 0;
                    else ans = probility;
                }
                return ;
            }

            for (auto& child : e[now]) {
                if (visited[child] == 0) {
                    visited[child] = 1;
                    dfs(child, probility / (e[now].size() - (now == 1 ? 0 : 1)), time - 1);
                }
            }
        };

        visited[1] = 1;
        dfs(1, 1.0, t);
        return ans;
    }
};
// @lc code=end

