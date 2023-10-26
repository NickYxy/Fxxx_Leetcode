/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            if (interval[0] > right) {
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left) {
                ans.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        if (!placed) ans.push_back({left, right});

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (!intervals.size()) return {newInterval};
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 0; i < intervals.size(); ++ i) {
            if (r < intervals[i][0]) {
                ans.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            } else {
                r = max(r, intervals[i][1]);
            }
        }

        ans.push_back({l, r});

        return ans;
    }
};
// @lc code=end

