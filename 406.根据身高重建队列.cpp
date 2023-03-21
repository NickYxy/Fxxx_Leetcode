/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i ++) {
            int pos = people[i][1];
            ans.insert(ans.begin() + pos, people[i]);
        }

        return ans;
    }
};

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        n = len(people)
        if n < 2:
            return people
        people.sort(key=lambda x:(-x[0], x[1]))
        que = []
        print(people)
        for p in people:
            que.insert(p[1], p)
        return que
// @lc code=end

