/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */

// @lc code=start
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    /*
        1、理一理思路，首先看DP的第一大境界到了没有，能否看出这是个DP问题？check
        2、明确是DP后，怎么做？有没有初步思路？这是DP第二大境界；
        假设a[:i - 1]是递增序列，那么a[i]应该怎么操作，可以分两种情况：sort(b)
        保留a[i]：定义函数keep[i] = min cost to make 0~i valid by keeping a
        不保留a[i]：定义函数swap[i][j] = min cost to make 0~i valid by swap a[i] and b[j]
        3、DP应该怎么定义？
        Init: keep[0] = 0: a[0] is always valid;
              swap[0][*] =1, assign b[j] to a[0], still valid but cost 1 step
        4、DP的状态转移方程怎么定义？
        Try all pairs:
        case1:a[i] > a[i-1],keep[i] = keep[i-1], i-1 reserved, i can still be reserved
        case2:b[j] > a[i-1],swap[i][j] =keep[i-1] + 1
        case3:a[i] > b[j],  keep[i] = min(swap[i-1][k]), k <= j;(b[k] <= b[j])
        case4:b[j] > b[k],  swap[i][j] = min(swap[i-1][k] + 1), k < j

        ans = min(min(swap[m-1]), keep[m-1]);
    */
        const int INF = 1e9;
        int m = a.size();
        sort(b.begin(), b.end());
        b.resize(unique(begin(b), end(b)) - begin(b)); // 去重
        int n = b.size();

        vector<int> keep(m, INF);
        vector<vector<int>> swapp(m, vector<int>(n, INF));

        for (int i = 0; i < n; ++ i) swapp[0][i] = 1;
        keep[0] = 0;

        for (int i = 1; i < m; ++ i) {
            int min_keep = INF, min_swap = INF;
            for (int j = 0; j < n; ++ j) {
                if (j > 0) min_swap = min(min_swap, swapp[i - 1][j - 1] + 1);
                if (a[i] > b[j]) min_keep = min(min_keep, swapp[i - 1][j]);
                if (a[i] > a[i - 1]) keep[i] = keep[i - 1];
                if (b[j] > a[i - 1]) swapp[i][j] = keep[i - 1] + 1; // 此时a[i] <= a[i - 1]
                swapp[i][j] = min(min_swap, swapp[i][j]);
                keep[i] = min(keep[i], min_keep);
            }
        }

        int s = *min_element(swapp.back().begin(), swapp.back().end());
        int k = keep.back();
        int ans = min(s, k);

        return ans == INF ? -1 : ans;
    }
};

class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()

        @cache
        def dfs(i: int, pre: int) -> int:
            if i == len(arr1): return 0
            res = inf
            # 换
            pos = bisect_right(arr2, pre)
            if pos < len(arr2):
                res = dfs(i + 1, arr2[pos]) + 1

            # 不换
            if arr1[i] > pre:
                res = min(res, dfs(i + 1, arr1[i]))
            return res

        ans = dfs(0, -1)
        return ans if ans != inf else -1
// @lc code=end

