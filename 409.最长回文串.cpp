/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        // 偶数次全取，奇数次减1
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i ++) {
            mp[s[i]] ++;
        }
        int ans = 0;
        for (auto& k : mp) {
            if(k.second % 2 == 0) ans += k.second;
            else ans += (k.second / 2) * 2;
        }
        if (ans == 0) return 1;
        if (ans < n &&(ans % 2 == 0)) ans ++;
        return ans;
    }
};
// @lc code=end

