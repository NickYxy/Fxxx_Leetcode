/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string ans = "";
        int i = 0;
        while (i < m || i < n) {
            if (i < m) ans += word1[i];
            if (i < n) ans += word2[i];
            i ++;
        }

        return ans;
    }
};
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string ans = "";
        for (int i = 0; i < min(m, n); ++ i) {
            ans += word1[i];
            ans += word2[i];
        }
        if (m > n) ans += word1.substr(n, m - n);
        else ans += word2.substr(m, n - m);

        return ans;
    }
};
// @lc code=end

