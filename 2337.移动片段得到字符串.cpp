/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 */

// @lc code=start
class Solution {
public:
    bool canChange(string start, string target) {
        // 如何定义target，双指针分别向中间遍历
        int m = start.size(), n = target.size();
        vector<char> s;
        vector<char> t;
        for (int i = 0; i < m; ++ i) {
            if (start[i] != '_') s.push_back(start[i]);
        }
        for (int i = 0; i < n; ++ i) {
            if (target[i] != '_') t.push_back(target[i]);
        }

        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++ i) if (s[i] != t[i]) return false;

        for (int i = 0, j = 0; i < start.size(); ++ i) {
            if (start[i] == '_') continue;
            while (target[j] == '_') j ++;
            if (i != j && start[i] == 'L' && i < j) return false;
            if (i != j && start[i] == 'R' && i > j) return false;
            j ++;
        }

        return true;
    }
};
// @lc code=end

