/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (auto& p : paths) {
            int a = p[0] - 1, b = p[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i ++ ) {
            vector<int> st(5, false); // 每次假设 4 种类型都没有用过
            for (auto& j : g[i]) // 标记相邻节点已经用过的类型
                st[res[j]] = true;

            for (int j = 1; j <= 4; j ++ ) { // 从 1-4 四种类型中任选一个没有被用过的
                if (!st[j]) {
                    res[i] = j;
                    break;
                }
            }
        }

        return res;
    }
};

class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        # 思路: 对于当前的某一个花园，剔除掉与它邻接花园的花的种类，从剩下的种类中选一种即可。
        # 1. 构建邻接矩阵G; 2. 用res列表保存当前花园花的种类
        ans = [0] * n
        g = [[] for _ in range(n)]
        for x, y in paths:
            g[x - 1].append(y - 1)
            g[y - 1].append(x - 1)

        for i in range(n):
            # 对于当前花园, 排除掉邻接的花园的花种就ok了，然后pop出一种
            ans[i] = ({1, 2, 3, 4} - {ans[i] for i in g[i]}).pop()

        return ans
// @lc code=end

