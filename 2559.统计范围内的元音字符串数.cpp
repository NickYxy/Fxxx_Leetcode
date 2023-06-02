/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 *
 * [2559] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        unordered_set<char> mp = {'a', 'e', 'i', 'o', 'u'};
        auto f = [&](string w) -> bool {
            if (w.size() == 1 && mp.count(w[0]) != 0) return true;
            if (mp.count(w[0]) != 0 && mp.count(w[w.size() - 1]) != 0) return true;
            return false;
        };

        vector<int> preSum(n);
        vector<int> num(n);
        for (int i = 0; i < n; ++ i) {
            if (f(words[i]) == true) num[i] = 1;
        }
        preSum[0] = num[0];
        for (int i = 1; i < n; ++ i) {
            preSum[i] = preSum[i - 1] + num[i];
        }

        vector<int> ans;
        for (auto q : queries) {
            if (q[0] == 0) ans.push_back(preSum[q[1]]);
            else ans.push_back(preSum[q[1]] - preSum[q[0] - 1]);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int prefixSums[n + 1];
        memset(prefixSums, 0, sizeof(prefixSums));
        for (int i = 0; i < n; i++) {
            int value = isVowelString(words[i]) ? 1 : 0;
            prefixSums[i + 1] = prefixSums[i] + value;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            ans[i] = prefixSums[end + 1] - prefixSums[start];
        }
        return ans;
    }

    bool isVowelString(const string &word) {
        return isVowelLetter(word[0]) && isVowelLetter(word.back());
    }

    bool isVowelLetter(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
// @lc code=end

