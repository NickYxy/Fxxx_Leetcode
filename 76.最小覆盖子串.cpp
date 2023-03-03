/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";
        if (s == t) return s;
        unordered_map<char, int> hs;
        unordered_map<char, int> ht;
        for (int i = 0; i < n; i ++) ht[t[i]] ++;
        int count = 0; //
        string res;

        for (int i = 0, j = 0; i < m; i++) {
            hs[s[i]] ++;
            if (hs[s[i]] <= ht[s[i]]) count ++;

            while (hs[s[j]] > ht[s[j]]) {
                hs[s[j]] --;
                j ++;
            }

            if (count == t.size()) {
                if (res.empty() || (i - j +1) < res.size()) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }

        return res;
    }
};
// @lc code=end

