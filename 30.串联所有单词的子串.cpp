/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> hashmap;
        for (auto& word : words) hashmap[word] ++;

        int n = s.size(), m = words.size(), len = words[0].size();
        for (int i = 0, j = 0; i < n - m * len + 1; i ++) {
            unordered_map<string, int> temphash;
            for (j = 0; j < m; j ++) {
                string sub = s.substr(i + j * len, len);
                if (!hashmap.count(sub)) break;
                if (++temphash[sub] > hashmap[sub]) break; //子串的个数超过了母串
            }
            if (j == m) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

