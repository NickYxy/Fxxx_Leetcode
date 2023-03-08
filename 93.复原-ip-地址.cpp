/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    void dfs(string s, int start, int k, string path) {
        if (k > 4) return; // 提前剪枝
        if (start == s.size()) {
            if (k == 4) {
                path.pop_back(); // 把最后的逗点去掉
                ans.push_back(path);
            }
        }

        for (int i = start, num = 0; i < s.size(); i ++) {
            if (i > start && s[start] == '0') break;
            num = num * 10 + s[i] - '0';
            if (num <= 255 && num >= 0) dfs(s, i + 1, k + 1, path + to_string(num) + '.');
            else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // 显然这是一个dfs问题, start表示搜索的起始位置，k表示已经添加的逗点数量
        if (s.size() < 4 || s.size() > 12) return ans;
        dfs(s, 0, 0, "");
        return ans;
    }
};
// @lc code=end

