/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution {
private:
    bool static cmp(const pair<char, int>&a, const pair<char, int>&b) {
        return a.second > b.second;
    }
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for (char ch : s) {
            mp[ch] ++;
            maxFreq = max(maxFreq, mp[ch]);
        }

        if (2 * maxFreq - 1 > s.size()) return "";

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);

        string ans(s);
        int idx = 0;
        for (int i = 0; i < vec.size(); ++ i) {
            while (vec[i].second --) {
                ans[idx] = vec[i].first;
                idx += 2;
                if (idx >= s.size()) idx = 1;
            }
        }

        return ans;
    }
};
// @lc code=end

