/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] 从字符串中移除星号
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        string res;
        for (auto& ch: s) {
            if (ch == '*') res.pop_back();
            else res += ch;
        }

        return res;
    }
};
class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<int> stk;
        int i = 0;
        while (i < n) {
            if (stk.empty() || s[i] != '*') stk.push(s[i]);
            else if (stk.size() && s[i] == '*') stk.pop();
            i ++;
        }

        string ans;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    string removeStars(string s) {
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                res.erase(res.begin()+res.length()-1,res.end());
                continue;
            }
            res+=s[i];
        }
        return res;
    }
};


func removeStars(s string) string {
	st := []rune{}
	for _, c := range s {
		if c == '*' {
			st = st[:len(st)-1]
		} else {
			st = append(st, c)
		}
	}
	return string(st)
}

// @lc code=end

