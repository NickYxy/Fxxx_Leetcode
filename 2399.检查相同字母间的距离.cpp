/*
 * @lc app=leetcode.cn id=2399 lang=cpp
 *
 * [2399] 检查相同字母间的距离
 */

// @lc code=start
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i ++) {
            if (mp.count(s[i]) == 0) {
                mp[s[i]] = i;
            } else {
                if (abs(i - mp[s[i]] - 1) == distance[s[i] - 'a']) continue;
                else return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> M(26, -1);
        for(int i=0;i<s.size();i++){
            int x = s[i]-'a';
            if(M[x]==-1)
                M[x] = i;
            else if(i-M[x]-1 != distance[x])
                return false;
        }
        return true;
    }
};
// @lc code=end

