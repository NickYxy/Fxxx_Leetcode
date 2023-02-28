/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        if (n <= 1) return n;
        unordered_map<char, int> mp;
        for (int i = 0, j = 0; i < n; i ++) {
            mp[s[i]] ++;
            while (mp[s[i]] > 1) {
                mp[s[j]] --;
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
// @lc code=end

