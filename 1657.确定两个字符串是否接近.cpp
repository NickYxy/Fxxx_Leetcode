/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // 第一个，word1中出现的字符在word2中都出现。

        // 第二个，字符出现的频次数相等。
        int m = word1.size(), n = word2.size();
        vector<int> l1, l2;
        unordered_map<char, int> mp1, mp2;

        if (m != n) return false;

        for (auto& w : word1) mp1[w] ++;
        for (auto& w : word2) {
            mp2[w] ++;
            if (word1.find(w) == word1.npos) return false; // 要判断一下两个字符串所含字符是否完全一样
        }

        for (auto& item : mp1) l1.emplace_back(item.second);
        for (auto& item : mp2) l2.emplace_back(item.second);

        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());

        return l1 == l2;
    }
};
// @lc code=end

