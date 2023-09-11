/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 起始时间start+duration <= lastDay;
        // start = start + duration;
        // how to decide which course to choose next, choose larger lastDay one
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {return c0[1] < c1[1];});

        priority_queue<int> q;
        int total = 0;

        for (const auto& course : courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            } else if (!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }

        return q.size();
    }
};
// @lc code=end

