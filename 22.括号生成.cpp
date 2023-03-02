/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    void dfs(int n, int lc, int rc, string seq){
        if (lc == n && rc == n) ans.push_back(seq);
        else {
            if (lc < n) dfs(n, lc + 1, rc, seq + "(");
            if (rc < n && lc > rc) dfs(n, lc, rc + 1, seq + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
};
// @lc code=end

