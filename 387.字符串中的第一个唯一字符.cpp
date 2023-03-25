/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        if (n == 1) return 0;
        for (int i = 0 ; i < n; i ++) mp[s[i]] ++;
        for (int i = 0 ; i < n; i ++) if (mp[s[i]] == 1) return i;

        return -1;
    }
};
// @lc code=end

