/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int n = prerequisites.size();

        vector<int> inDegree(numCourses);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++ i) {
            inDegree[prerequisites[i][0]] ++;
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++ i) {
            if (inDegree[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();

            vector<int> relyOn = mp[cur];
            for (int i = 0; i < relyOn.size(); ++ i) {
                inDegree[relyOn[i]] --;
                if (inDegree[relyOn[i]] == 0) {
                    ans.push_back(relyOn[i]);
                    q.push(relyOn[i]);
                }
            }
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};
// @lc code=end

