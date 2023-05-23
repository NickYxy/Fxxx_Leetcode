/*
 * @lc app=leetcode.cn id=1090 lang=cpp
 *
 * [1090] 受标签影响的最大值
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> PII;
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        // 元素数量小于wanted，有相同标签的不能超过limit
        // 首先要选最大的，然后在满足limit的情况下，尽量取最大值
        int n = values.size();
        int ans = 0;
        unordered_map<int, int> mp;
        vector<PII> source;
        for (int i = 0; i < n; ++ i) {
            source.emplace_back(values[i], labels[i]);
        }

        sort(source.rbegin(), source.rend());
        for (int i = 0; i < n; ++ i) {
            auto& [k, v] = source[i];
            if (mp[v] < useLimit && numWanted) {
                ans += k;
                numWanted --;
                mp[v] ++;
            }
        }

        return ans;
    }
};
// @lc code=end

