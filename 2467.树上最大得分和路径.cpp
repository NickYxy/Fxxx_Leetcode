/*
 * @lc app=leetcode.cn id=2467 lang=cpp
 *
 * [2467] 树上最大得分和路径
 */

// @lc code=start
class Solution {
public:
    vector<int> bob_time; // bobTime[x] 表示 bob 访问节点 x 的时间
    int n;
    int ans = INT_MIN;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size();
        bob_time.assign(n, n);// 也可以初始化成 inf
        vector<vector<int>> g(n);
        // 建树
        for (auto& edge : edges) {
            g[edge[0]].emplace_back(edge[1]);
            g[edge[1]].emplace_back(edge[0]);
        }

        g[0].emplace_back(-1);// 防止把根节点当作叶子

        dfs_1(g, bob, -1, 0);
        dfs_2(g, 0, -1, 0, 0, amount);

        return ans;
    }

    bool dfs_1(vector<vector<int>>& g, int bob, int vis, int time) {
        bob_time[bob] = time;
        if (bob == 0) return true; // bob走到0，结束

        for (int i = 0; i < g[bob].size(); i ++) {
            if (g[bob][i] == vis) continue;
            int next_bob = g[bob][i];
            if (dfs_1(g, next_bob, bob, time + 1)) return true;
            bob_time[next_bob] = n;
        }

        return false;
    }

    void dfs_2(vector<vector<int>>& g, int alice, int vis, int time, int score, vector<int>& amount) {
        if (bob_time[alice] == time) {
            score += amount[alice] / 2;
        }

        if (bob_time[alice] > time) {
            score += amount[alice];
        }

        if (g[alice].size() == 1) { // 走到了叶子结点，更新答案
            ans = max(ans, score);
        }

        for (int i = 0; i < g[alice].size(); i ++) {
            if (g[alice][i] == vis) continue;
            int next_alice = g[alice][i];
            dfs_2(g, next_alice, alice, time + 1, score, amount);
        }
    }
};
// @lc code=end

