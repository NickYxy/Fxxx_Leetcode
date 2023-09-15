/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), len = 0;
        for (int i = 0, cnt = 1; i < n; i ++, cnt ++) {
            if (i == n - 1 || chars[i] != chars[i + 1]) {
                chars[len++] = chars[i];
                if (cnt > 1) {
                    for (char ch : to_string(cnt)) chars[len++] = ch;
                }
                cnt = 0;
            }
        }

        return len;
    }
};
// @lc code=end

