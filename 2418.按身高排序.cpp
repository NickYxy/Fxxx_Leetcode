/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 *
 * [2418] 按身高排序
 */

// @lc code=start
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int, string> mp;

        for (int i = 0; i < heights.size(); i++) {
            mp[heights[i]] = names[i];
        }

        for (auto it = mp.begin(); it!= mp.end(); it++) {
            ans.push_back(it->second);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        if (names.size() == 1) return names;
        vector<string> res;
        vector<pair<int, string>> s;
        for (int i = 0; i < names.size(); i ++ ) {
            s.push_back({-heights[i], names[i]});
        }

        sort(s.begin(), s.end());
        for (auto x : s) {
            res.push_back(x.second);
        }

        return res;
    }
};
// @lc code=end

