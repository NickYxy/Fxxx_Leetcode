/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start
class Solution {
public:
    int longestDecomposition(string text) {
        // 贪心模拟即可，这叫《应分尽分》《能分就分》《可分必分》
        // 最后中间不能再分加1即可
        for (int i = 1; i <= text.size() / 2; i ++) {
            if (text.substr(0, i) == text.substr(text.size() - i, i))
                return longestDecomposition(text.substr(i, text.size() - 2 * i)) + 2;

        }

        return min(1, int(text.size()));
    }
};
// @lc code=end

