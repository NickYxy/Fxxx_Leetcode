/*
 * @lc app=leetcode.cn id=2446 lang=cpp
 *
 * [2446] 判断两个事件是否存在冲突
 */

// @lc code=start
class Solution {
public:
    bool haveConflict(vector<string>& a, vector<string>& b) {
        return !(a[1] < b[0] || a[0] > b[1]);
    }
};

class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        a1 = self.getTime(event1[0])
        a2 = self.getTime(event1[1])
        b1 = self.getTime(event2[0])
        b2 = self.getTime(event2[1])

        return not a2 < b1 and not b2 < a1

    def getTime(self, s) -> int:
        a = int(s[:2]) * 60
        b = int(s[3:])
        return a + b
// @lc code=end

