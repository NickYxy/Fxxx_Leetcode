/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string str;
        vector<string> st;
        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') i ++;
            else {
                for (; i < path.size() && path[i] != '/'; ++ i) str += path[i];
                if (str == ".");
                else if (str == "..") {
                    if (!st.empty()) st.pop_back();
                }else {
                    st.push_back(str);
                }
                str = "";
            }
        }

        if (st.empty()) return "/";
        string ans;
        for (auto& s : st) {
            ans += ('/' + s);
        }

        return ans;
    }
};
// @lc code=end

