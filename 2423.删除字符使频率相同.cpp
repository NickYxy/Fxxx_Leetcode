/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
 */

// @lc code=start
class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        vector<int> frequency(26, 0);
        for (auto& ch : word) frequency[ch - 'a'] ++; // 统计单词的频率
        for (int i = 0; i < 26; ++ i) {
            if (frequency[i] == 0) continue;
            frequency[i] --; // 将单词的频率减1，然后看剩下的所有频率是否是同一种
            unordered_set<int> s;
            for (auto& f : frequency) {
                if (f > 0) s.insert(f);
            }
            if (s.size() == 1) return true; // set里只有一种频率数，证明可解
            frequency[i] ++;
        }
        return false;
    }
};
// @lc code=end

