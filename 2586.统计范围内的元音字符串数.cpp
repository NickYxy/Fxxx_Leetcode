/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right && i < words.size(); ++ i) {
            if (check(words[i])) ans ++;
        }

        return ans;
    }

    bool check(string word) {
        if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') && (word[word.size() - 1] == 'a' || word[word.size() - 1] == 'e' || word[word.size() - 1] == 'i' || word[word.size() - 1] == 'o' || word[word.size() - 1] == 'u'))return true;

        return false;
    }
};
// @lc code=end

