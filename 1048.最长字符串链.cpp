/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto& word : words) mp[word] = 0; // 0 表示未被计算
        function<int(string)> dfs = [&](string s) -> int {
            int res = mp[s];
            if (res) return res;
            for (int i = 0; i < s.size(); ++ i) {
                auto t = s.substr(0, i) + s.substr(i + 1);
                if (mp.count(t)) res = max(res, dfs(t));
            }
            return mp[s] = res + 1;
        };

        int ans = 0;
        for (auto& [s, _] : mp) ans = max(ans, dfs(s));
        return ans;
    }
};

class Solution {
public:
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> ws;
        for (auto &s: words) ws[s] = 0; // 0 表示未被计算
        function<int(string)> dfs = [&](string s) -> int {
            int res = ws[s];
            if (res) return res; // 之前计算过
            for (int i = 0; i < s.length(); ++i) { // 枚举去掉 s[i]
                auto t = s.substr(0, i) + s.substr(i + 1);
                if (ws.count(t)) // t 在 words 中
                    res = max(res, dfs(t));
            }
            return ws[s] = res + 1; // 记忆化
        };
        int ans = 0;
        for (auto &[s, _]: ws)
            ans = max(ans, dfs(s));
        return ans;
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1, n = words.size();
        auto cmp = [&](string& a, string& b)->bool {return a.size() < b.size();};
        sort(begin(words), end(words), cmp);

        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                if ((words[i].size() - words[j].size() == 1) && isTrue(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }

        return ans;
    }

    bool isTrue(string l, string r) {
        if ((r.size() - l.size()) != 1) return false;

        int i = 0, j = 0;
        while (i < l.size()) {
            if (l[i] == r[j]) i ++;
            j ++;
            if (j - i > 1) return false;
        }

        return true;
    }
};
// @lc code=end

