/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */

// @lc code=start
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        vector<int> temp;
        for (int i = 0; i < words.size(); ++ i) {
            temp.push_back(calculateFrequency(words[i]));
        }
        for (int i = 0; i < queries.size(); ++ i) {
            int cnt = 0;
            for (auto& t : temp) {
                if (calculateFrequency(queries[i]) < t) cnt ++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }

    int calculateFrequency(string s) {
        pair<char, int> p(s[0], 1);
        for (int i = 1; i < s.size(); ++ i) {
            if (s[i] - p.first > 0) continue;
            else if (s[i] == p.first) p.second ++;
            else {
                p.first = s[i];
                p.second = 1;
            }
        }

        return p.second;
    }
};

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](string &s) {
            int cnt = 0;
            char ch = 'z';
            for (char c : s) {
                if (c < ch) {
                    ch = c;
                    cnt = 1;
                } else if (c == ch) {
                    cnt++;
                }
            }
            return cnt;
        };
        int count[12] = {0};
        vector<int> ans;
        for (auto &s : words) {
            count[f(s)]++;
        }
        for (int i = 9; i > 0; i--) {
            count[i] += count[i + 1];
        }
        for (auto &s : queries) {
            ans.push_back(count[f(s) + 1]);
        }
        return ans;
    }
};
// @lc code=end

