/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 图问题，如果是无环图，则可以学完，否则不可以
        int n = prerequisites.size();
        if (n == 0) return true;
        unordered_map<int, vector<int>> mp;
        vector<int> inDegree(numCourses);
        for (int i = 0; i < n; i ++) {
            inDegree[prerequisites[i][0]] ++; //当前课程入度值+1
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]); //添加依赖他的后续课
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) q.push(i); //所有入度为0的课入列
        }

        int count = 0;
        while (q.size()) {
            int cur = q.front(); //当前选的课
            q.pop();
            count ++;//选课数+1
            vector<int> relyOn = mp[cur]; //获取这门课对应的后续课
            if (relyOn.size()) {
                for (int i = 0; i < relyOn.size(); i ++) {
                    inDegree[relyOn[i]] --; //依赖它的后续课的入度-1
                    if (inDegree[relyOn[i]] == 0) q.push(relyOn[i]); //如果因此减为0，入列
                }
            }
        }

        if (count == numCourses) return true;
        return false;
    }
};
// @lc code=end

