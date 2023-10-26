/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string tmp, ans;
    int idx = 0;
    string getPermutation(int n, int k) {
        vector<int> used(n);
        backtrack(n, k, k, used);
        return ans;
    }

    void backtrack(int n, int k, int diff, vector<int>& used) {
        if (idx == k + 1) return;
        if (tmp.size() == n) {
            idx ++;
            if (idx == k) ans = tmp;
            return;
        }

        for (int i = 1; i <= n; ++ i) {
            int cur = factorial(n - tmp.size() - 1);
            if (diff > cur) {
                diff -= cur;
                idx += cur;
                continue;
            }

            if (used[i - 1] == 0) {
                diff -= cur;
                used[i - 1] = 1;
                tmp += to_string(i);
                backtrack(n, k, diff, used);
                tmp.pop_back();
                used[i - 1] = 0;
            }
        }
    }

    int factorial(int n) {
        if (n == 1 || n == 0) return 1;
        return n * factorial(n - 1);
    }
};
// @lc code=end

