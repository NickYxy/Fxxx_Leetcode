/*
 * @lc app=leetcode.cn id=1494 lang=cpp
 *
 * [1494] 并行课程 II
 */

// @lc code=start
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        int pre1[n];
        //存储1-n的先行课，1为先行课
        memset(pre1, 0, sizeof(pre1));
        for (auto &r: relations)
            pre1[r[1] - 1] |= 1 << (r[0] - 1);
        // r[1] 的先修课程集合，下标改从 0 开始
        int u = (1 << n) - 1;
        // 全集，全部的课都变为1
        int memo[1 << n];
        memset(memo, -1, sizeof(memo));
        // -1 表示没有计算过
        function<int(int)> dfs = [&](int i) -> int {
            if (i == 0) return 0;
            // 空集，证明课上完了
            int &res = memo[i];
            // 注意这里是引用
            //int* const res=&memo[i]
            //*res=100;
            if (res != -1) return res;
            // 之前算过了
            int i1 = 0, ci = u ^ i;
            // u为全1，i是上课的为1，ci为上完的为1
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1 && (pre1[j] | ci) == ci)
                //(i >> j) & 1判断这一位是否为1，是1代表没学，
                //pre1[j]代表j的先行课，要上的先行课为1，
                //pre1[j] | ci代表先行课都上了，可以学习j课程
                //pre1[j] 在 i 的补集中，可以学（否则这学期一定不能学）
                    i1 |= 1 << j;
                //i1用来记录这一学期哪一课程可以学，1为可以学
            if (__builtin_popcount(i1) <= k)
                // 如果个数小于 k，则可以全部学习，不再枚举子集
                return res = dfs(i ^ i1) + 1;
                //i存储没学的课程，i1存储可以学的课程，
                //i ^ i1代表学完之后没有学习的课程
            res = INT_MAX;
            //大于k，枚举每次上k个课程，取最小值
            for (int j = i1; j; j = (j - 1) & i1)
            // 枚举 i1 的子集 j
            //从大到小，判断正好能学k个的情况,牛皮
                if (__builtin_popcount(j) == k)
                    res = min(res, dfs(i ^ j) + 1);
            //取最小值返回
            return res;
        };
        return dfs(u);
    }
};
// @lc code=end

