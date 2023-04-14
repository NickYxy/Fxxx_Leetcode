/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string p) {
        int n = queries.size();
        vector<bool> ans(n, true);
        for (int i = 0; i < n; i ++) {
            if (check(queries[i], p)) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }

    bool check(string q, string p) {
        int i = 0;
        // 对pattern里的每个char在q里寻找，如果相等就继续
        // 如果q的元素是大写，但是此时两者并不相等，则不匹配
        // 如果q已经遍历完，pattern依然没有匹配完，返回false
        for (auto& c : q) {
            if (i < p.size() && p[i] == c) i ++;
            else if (isupper(c)) return false;
        }
        if (i < p.size()) return false;
        return true;
    }
};
// @lc code=end

