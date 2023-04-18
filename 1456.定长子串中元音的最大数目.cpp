/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution {
public:
    bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < k; i ++) {
            if (check(s[i])) cnt ++;
        }

        ans = cnt;
        for (int i = k; i < s.size(); i ++) {
            if (check(s[i - k])) cnt --;
            if (check(s[i])) {
                cnt ++;
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        cnt = 0
        for i in range(k):
            if s[i] in vowels:
                cnt += 1
        res = cnt

        for i in range(k, len(s)):
            if s[i - k] in vowels:
                cnt -= 1
            if s[i] in vowels:
                cnt += 1
                res = max(res, cnt)
        return res
// @lc code=end

