/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> mp;/记录char c 和其最后出现位置的 map
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, mp[s[i]]);// 找到字符出现的最远边界
            if (i == end) {
                // 如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
                res.emplace_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

